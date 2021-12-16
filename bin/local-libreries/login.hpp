/**
 * login.hpp
 *
 * Library to handle login and inizialization
 *
 * @author Davide Castellani (@DavideC03)
 */

#ifndef LOGIN
// If not imported yet
#define LOGIN

// Dependencies
#include <bits/stdc++.h>
#include <unistd.h>
#include "../global-libraries/bin/inputs.hpp"
#include "../global-libraries/bin/rest.hpp"
#include "memory.hpp"

// using ...
using namespace std;

// Definitions
// #define DEBUG

// Classes prototipe(s)
class Login
{
private:
	Inputs inputs;
	inline static vector<pair<string, string>> needed_info = { // variable name, Ask to do, if not inserted as launch parameter
		{"username", "Insert username: "},
		{"password", "Insert password: "},
		{"server-name", "Insert server name: "},
		{"server-password", "Insert server password: "}};
	map<string, string> info;

public:
	Login(Inputs inputs);

	void execute();

	static void execute(Inputs inputs);
};

// Function(s)
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
	if (getuid())
	{
		cout << "Please run login as root" << endl;
		cout << "eg. \"sudo manager --login\"" << endl;
		cout << endl
			 << "More info in the manual: \"man manager\"" << endl;
		return;
	}

	for (auto &[key, ask] : Login::needed_info)
	{
		if (Login::inputs.exist("--" + key) && Login::inputs.getValue("--" + key).compare("") != 0)
		{
			Login::info[key] = Login::inputs.getValue("--" + key);
		}
		else
		{
			cout << ask;
			cin >> Login::info[key];
		}
	}

#ifdef DEBUG
	cout << "Login info:" << endl;
	for (auto &[key, value] : Login::info)
	{
		cout << "\t" << key << ": " << value << endl;
	}
#endif // DEBUG

	// Install Docker
	system(
		" \
		docker --version > /dev/null || { \
			curl -fsSL https://download.docker.com/linux/ubuntu/gpg | gpg --dearmor -o /usr/share/keyrings/docker-archive-keyring.gpg; \
			echo \"deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/docker-archive-keyring.gpg] https://download.docker.com/linux/ubuntu $(lsb_release -cs) stable\" | tee /etc/apt/sources.list.d/docker.list > /dev/null; \
			apt-get update > /dev/null; \
			apt-get install docker-ce docker-ce-cli containerd.io -y > /dev/null; \
			groupadd docker; \
			usermod -aG docker $(logname); \
		} \
		");

#ifdef DEBUG
	cout << "Docker installed" << endl;
#endif // DEBUG

	// Install & Start minikube
	system(
		" \
		minikube version > /dev/null || { \
			curl -LO https://storage.googleapis.com/minikube/releases/latest/minikube-linux-$(dpkg --print-architecture); \
			sudo install minikube-linux-$(dpkg --print-architecture) /usr/local/bin/minikube; \
		} \
		");

	system("sudo -u $(logname) minikube start");
	
#ifdef DEBUG
	cout << "Minikube installed & started" << endl;
#endif // DEBUG

	// Install Kubernetes
	system(
		"sudo -u $(logname) kubectl version > /dev/null || { \
			curl -s https://packages.cloud.google.com/apt/doc/apt-key.gpg | apt-key add -; \
			echo \"deb https://apt.kubernetes.io/ kubernetes-xenial main\" | tee /etc/apt/sources.list.d/kubernetes.list; \
			apt-get update > /dev/null; \
			apt-get install -y kubelet kubeadm kubectl > /dev/null; \
			apt-mark hold kubelet kubeadm kubectl > /dev/null; \
		}"
		);

#ifdef DEBUG
	cout << "Kubernetes installed" << endl;
#endif // DEBUG

	// Import ssh keys from github account
	system((
			   " \
				ssh-import-id-gh " +
			   Login::info["username"] + " \
			").c_str());

#ifdef DEBUG
	cout << "ssh keys imported" << endl;
#endif // DEBUG

	// Create the stratup service
	system(
		" \
		echo \"[Unit]\" > /etc/systemd/system/createstructure.service; \
		echo \"Description=Start minikube\" >> /etc/systemd/system/createstructure.service; \
		echo \"After=network.service\" >> /etc/systemd/system/createstructure.service; \
		echo \"\" >> /etc/systemd/system/createstructure.service; \
		echo \"[Service]\" >> /etc/systemd/system/createstructure.service; \
		echo \"ExecStart=/usr/local/bin/minikube start\" >> /etc/systemd/system/createstructure.service; \
		echo \"Type=oneshot\" >> /etc/systemd/system/createstructure.service; \
		echo \"RemainAfterExit=yes\" >> /etc/systemd/system/createstructure.service; \
		echo \"User=$(logname)\" >> /etc/systemd/system/createstructure.service; \
		echo \"TimeoutSec=0\" >> /etc/systemd/system/createstructure.service; \
		echo \"\" >> /etc/systemd/system/createstructure.service; \
		echo \"[Install]\" >> /etc/systemd/system/createstructure.service; \
		echo \"WantedBy=default.target\" >> /etc/systemd/system/createstructure.service; \
		echo \"\" >> /etc/systemd/system/createstructure.service; \
		chmod a+rwx /etc/systemd/system/createstructure.service; \
		systemctl enable createstructure.service > /dev/null; \
		");

#ifdef DEBUG
	cout << "Startup service created" << endl;
#endif // DEBUG

	// Create key pair
	system("openssl genrsa -out /tmp/private.pem 4096 > /dev/null && chmod +rwx /tmp/private.pem");
	system("openssl rsa -in /tmp/private.pem -outform PEM -pubout -out /tmp/public.pem > /dev/null && chmod +rwx /tmp/public.pem");

	// Print key pair
	cout << "Private key: " << endl;
	system("cat /tmp/private.pem");
	cout << "Public key: " << endl;
	system("cat /tmp/public.pem");

	cout << "Press any key to continue" << endl;
	cin.get();

	// Create K8s secret(s)
	system("sudo -u $(logname) kubectl delete secret auth --ignore-not-found");	  // Delete secret if already exists
	system("sudo -u $(logname) kubectl delete secret docker --ignore-not-found"); // Delete secret if already exists
	system((
			   string("") +
			    "sudo -u $(logname) kubectl create secret generic auth " +
			   "--from-literal=server_name=\"" + Login::info["server-name"] + "\" " +
			   "--from-literal=server_password=\"" + Login::info["server-password"] + "\" " +
			   "--from-file=server_gpg_key=/tmp/private.pem")
			   .c_str());
	system((
			   string("") +
			   "sudo -u $(logname) kubectl create secret docker-registry docker" + " " +
			   "--docker-server=https://ghcr.io" + " " +
			   "--docker-username=\"" + Login::info["username"] + "\" " +
			   "--docker-password=\"" + Login::info["password"] + "\" " +
			   "--docker-email=davidecastellani@castellanidavide.it")
			   .c_str());

	// Delete key pair
	system("rm /tmp/private.pem");
	system("rm /tmp/public.pem");

	// Create/ Update Kubectl config
	string toReplace = "1 # Number of replicas";
	long long replicas = max(
		(Memory::getTotalMemory(Memory::MB) - 1500) / 100,
		(long long)1);

#ifdef DEBUG
	cout << "Replicas: " << replicas << endl;
#endif // DEBUG

	string config = string("") +
					"apiVersion: apps/v1" + "\n" +
					"kind: ReplicaSet" + "\n" +
					"metadata:" + "\n" +
					"  name: manager" + "\n" +
					"  labels:" + "\n" +
					"    app: manager" + "\n" +
					"spec:" + "\n" +
					"  replicas: 1 # Number of replicas" + "\n" +
					"  selector:" + "\n" +
					"    matchLabels:" + "\n" +
					"      app: core" + "\n" +
					"  template:" + "\n" +
					"    metadata:" + "\n" +
					"      name: core" + "\n" +
					"      labels:" + "\n" +
					"        app: core" + "\n" +
					"    spec:" + "\n" +
					"      containers:" + "\n" +
					"      - name: core" + "\n" +
					"        image: ghcr.io/createstructure/core-createstructure:" +
#ifdef DEBUG
						"beta" + "\n" +
#else // DEBUG
						"latest" + "\n" +
#endif // DEBUG
					"        imagePullPolicy: \"Always\"" + "\n" +
					"        volumeMounts:" + "\n" +
					"        - name: auth" + "\n" +
					"          readOnly: true" + "\n" +
					"          mountPath: \"/etc/auth\"" + "\n" +
					"      imagePullSecrets:" + "\n" +
					"      - name: docker # Secret with Docker config" + "\n" +
					"      volumes:" + "\n" +
					"      - name: auth" + "\n" +
					"        secret:" + "\n" +
					"          secretName: auth";

	config.replace(config.find(toReplace), toReplace.length(), to_string(replicas));

#ifdef DEBUG
	cout << "Config: " << config << endl;
#endif // DEBUG

	system((
			   "echo '" +
			   config +
			   "' | sudo -u $(logname) kubectl apply -f -")
			   .c_str());
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

#undef DEBUG
#endif
