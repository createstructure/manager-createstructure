/**
 * login.cpp
 *
 * Library to handle login and inizialization
 *
 * @author Davide Castellani (@DavideC03)
 */

// Dependencies
#include "login.hpp"

// Definitions
#define DEBUG

Login::Login(Inputs inputs)
{
	/**
	 * Constructor
	 *
	 * @param inputs Inputs object
	 */
	Login::inputs = inputs;
}

void Login::execute()
{
	/**
	 * Execute
	 */
	if (getuid() || !Login::inputs.exist("--login") || !Login::inputs.exist("--server-name"))
	{
		cerr << "Please run login as root" << endl
			 << "eg.\"sudo manager --login ... --server-name ...\"" << endl
			 << endl
			 << "More info in the manual:\"man manager\"" << endl;
		return;
	}
	
	Login::password = Login::inputs.getValue("--login");
	Login::servername = Login::inputs.getValue("--server-name");
	Login::get_username();
	Login::generate_server_password();
	Login::generate_server_keys();

#ifdef DEBUG
	cout << "Username: " << Login::username << endl
		 << "Password: " << Login::password << endl
		 << "Servername: " << Login::servername << endl
		 << "Server password: " << Login::server_password << endl
		 << "Server public key: " << endl
		 << Login::server_public_key << endl
		 << "Server private key: " << endl
		 << Login::server_private_key << endl;
#endif // DEBUG

	Login::register_server();
	Login::configure_ssh();
	Login::install_docker();
	Login::install_minikube();
	Login::create_onstartup_service();
}

void Login::execute(Inputs inputs)
{
	/**
	 * Execute
	 *
	 * @param inputs Inputs object
	 */
	Login login(inputs);
	login.execute();
}

void Login::get_username()
{
	json info = Rest::jsonRequest(
		Rest::GITHUB_REST_API + "user",
		Login::password);

	if (info["login"].is_string())
	{
		Login::username = info["login"].get<string>();
	}
	else
	{
		cerr << Emoji::getEmoji("x") << "\tWrong token, check it again" << endl;
		exit(1);
	}
}

void Login::generate_server_password()
{
	Login::server_password = Login::system("openssl rand -base64 128 | tr -d '\n'");
}

void Login::generate_server_keys()
{
	system("openssl genrsa -out /tmp/private.pem 4096 > /dev/null && chmod +rwx /tmp/private.pem");
	system("openssl rsa -in /tmp/private.pem -outform PEM -pubout -out /tmp/public.pem > /dev/null && chmod +rwx /tmp/public.pem");

	ifstream privatefile("/tmp/private.pem");
	ifstream publicfile("/tmp/public.pem");

	{
		privatefile.seekg(0, std::ios::end);
		size_t size = privatefile.tellg();
		string buffer(size, ' ');
		privatefile.seekg(0);
		privatefile.read(&buffer[0], size);
		Login::server_private_key = buffer;
	}

	{
		publicfile.seekg(0, std::ios::end);
		size_t size = publicfile.tellg();
		string buffer(size, ' ');
		publicfile.seekg(0);
		publicfile.read(&buffer[0], size);
		Login::server_public_key = buffer;
	}

	privatefile.close();
	publicfile.close();

	Login::sanitize(Login::server_private_key);
	Login::sanitize(Login::server_public_key);

	// Delete key pair
	system("rm /tmp/private.pem");
	system("rm /tmp/public.pem");

#ifdef DEBUG
	cout << "Keys generated installed" << endl;
#endif // DEBUG
}

void Login::register_server()
{
	json request;
	request["request"] = "create_server";
	request["username"] = Login::username;
	request["token"] = Login::password;
	request["server_name"] = Login::servername;
	request["server_password"] = Login::server_password;
	request["server_description"] = "Created automatically by manager-createstructure";
	request["server_public_key"] = Login::server_public_key;

	cout << Rest::textRequest(
		Rest::CREATESTRUCTURE_REST_API,
		Login::password,
		request,
		true);
}

string Login::system(string input)
{
	char buffer[128];
	string res = "";
	FILE *pipe = popen(input.c_str(), "r");

	if (!pipe)
		throw runtime_error("System failed");
	try
	{
		while (fgets(buffer, sizeof buffer, pipe) != NULL)
		{
			res += buffer;
		}
	}
	catch (...)
	{
		pclose(pipe);
		throw;
	}
	pclose(pipe);
	return res;
}

void Login::install_docker()
{
	// Install Docker
	system(
		"\
		docker --version > /dev/null || {\
			curl -fsSL https://download.docker.com/linux/ubuntu/gpg | gpg --dearmor -o /usr/share/keyrings/docker-archive-keyring.gpg;\
			echo\"deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/docker-archive-keyring.gpg] https://download.docker.com/linux/ubuntu $(lsb_release -cs) stable\" | tee /etc/apt/sources.list.d/docker.list > /dev/null;\
			apt-get update > /dev/null;\
			apt-get install docker-ce docker-ce-cli containerd.io -y > /dev/null;\
			groupadd docker;\
			usermod -aG docker $(logname);\
			service docker start;\
		}\
		");

#ifdef DEBUG
	cout << "Docker installed" << endl;
#endif // DEBUG
}

void Login::install_minikube()
{
	// Install & Start minikube
	system(
		"\
		minikube version > /dev/null || {\
			curl -LO https://storage.googleapis.com/minikube/releases/latest/minikube-linux-$(dpkg --print-architecture);\
			sudo install minikube-linux-$(dpkg --print-architecture) /usr/local/bin/minikube;\
			rm minikube-linux-$(dpkg --print-architecture);\
		}\
		");

	system("sudo -u $(logname) minikube start");

#ifdef DEBUG
	cout << "Minikube installed & started" << endl;
#endif // DEBUG

	// Install Kubernetes
	system(
		"sudo -u $(logname) kubectl version > /dev/null || {\
			curl -s https://packages.cloud.google.com/apt/doc/apt-key.gpg | apt-key add -;\
			echo\"deb https://apt.kubernetes.io/ kubernetes-xenial main\" | tee /etc/apt/sources.list.d/kubernetes.list;\
			apt-get update > /dev/null;\
			apt-get install -y kubelet kubeadm kubectl > /dev/null;\
			apt-mark hold kubelet kubeadm kubectl > /dev/null;\
		}");

#ifdef DEBUG
	cout << "Kubernetes installed" << endl;
#endif // DEBUG

	// Create K8s secret(s)
	system("sudo -u $(logname) kubectl delete secret auth --ignore-not-found");   // Delete secret if already exists
	system("sudo -u $(logname) kubectl delete secret docker --ignore-not-found"); // Delete secret if already exists
	system((
			   string("") +
			   "sudo -u $(logname) kubectl create secret generic auth " +
			   "--from-literal=server_name=\"" + Login::servername + "\" " +
			   "--from-literal=server_password=\"" + Login::server_password + "\" " +
			   "--from-literal=server_gpg_key=\"" + Login::server_private_key + "\"")
			   .c_str());
	system((
			   string("") +
			   "sudo -u $(logname) kubectl create secret docker-registry docker" + " " +
			   "--docker-server=https://ghcr.io" + " " +
			   "--docker-username=\"" + Login::username + "\" " +
			   "--docker-password=\"" + Login::password + "\" " +
			   "--docker-email=davidecastellani@castellanidavide.it")
			   .c_str());

	// Create/ Update Kubectl config
	string toReplace = "1 # Number of replicas";
	long long replicas = max(
		(Memory::getTotalMemory(Memory::MB) - 2000) / 150,
		(long long)1);

#ifdef DEBUG
	cout << "Replicas: " << replicas << endl;
#endif // DEBUG

	Login::KUBERNATES_CONFIG.replace(Login::KUBERNATES_CONFIG.find(toReplace), toReplace.length(), to_string(replicas));
	Login::sanitize(Login::KUBERNATES_CONFIG);

#ifdef DEBUG
	cout << "Config: " << Login::KUBERNATES_CONFIG << endl;
#endif // DEBUG

	system((
			   "printf '" +
			   Login::KUBERNATES_CONFIG +
			   "' | sudo -u $(logname) kubectl apply -f -")
			   .c_str());
}

void Login::configure_ssh()
{
	// Import ssh keys from github account
	system((
			   "\
				ssh-import-id-gh " +
			   Login::username + "\
			")
			   .c_str());

#ifdef DEBUG
	cout << "ssh keys imported" << endl;
#endif // DEBUG
}

void Login::create_onstartup_service()
{
	// Create the stratup service
	ofstream service("/etc/systemd/system/createstructure.service");

	if (service.fail())
	{
		cerr << "Error creating service";
		exit(1);
	}

	string logname_old = "$(logname)";
	string logname_new = Login::system("echo $(logname);");
	Login::SERVICE.replace(Login::SERVICE.find(logname_old), logname_old.size(), logname_new);

	service.write(Login::SERVICE.c_str(), Login::SERVICE.length());
	service.flush(); // Make sure all changes to be salved
	service.close();

	system(
		"chmod a+rwx /etc/systemd/system/createstructure.service;\
		systemctl daemon-reload;\
		systemctl unmask createstructure.service > /dev/null;\
		systemctl enable createstructure.service > /dev/null;");

#ifdef DEBUG
	cout << "Startup service created" << endl;
#endif // DEBUG
}

void Login::sanitize(string &s)
{
	string from_ = "\n";
	string to_ = "\\n";

	for (size_t pos = 0; (pos = s.find(from_, pos) + 1); pos += to_.size())
		s.replace(--pos, from_.size(), to_);
}

#undef DEBUG
