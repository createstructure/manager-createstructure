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
#include <iostream>
#include <string>
#include <unistd.h>
#include <fstream>
#include "../global-libraries/bin/inputs.hpp"
#include "../global-libraries/bin/rest.hpp"
#include "../global-libraries/bin/json.hpp"
#include "../global-libraries/bin/emoji.hpp"
#include "memory.hpp"

// using ...
using namespace std;

// Classes prototipe(s)
class Login
{
private:
	Inputs inputs;
	string username;
	string password;
	string servername;
	string server_password;
	string server_private_key;
	string server_public_key;
	const string SERVICE = "[Unit]\n \
Description=Start minikube\n \
After=network.service\n \
\n \
[Service]\n \
ExecStart=minikube start\n \
Type=oneshot\n \
RemainAfterExit=yes\n \
User=$(logname)\n \
TimeoutSec=0\n \
\n \
[Install]\n \
WantedBy=default.target\n \
\n \
";

	string KUBERNATES_CONFIG = "apiVersion: apps/v1\n \
kind: ReplicaSet\n \
metadata:\n \
  name: manager\n \
  labels:\n \
    app: manager\n \
spec:\n \
  replicas: 1 # Number of replicas\n \
  selector:\n \
    matchLabels:\n \
      app: core\n \
  template:\n \
    metadata:\n \
      name: core\n \
      labels:\n \
        app: core\n \
    spec:\n \
      containers:\n \
      - name: core\n \
        image: ghcr.io/createstructure/core-createstructure:latest #'beta' to don't release as stable, 'latest' otherwise\n \
        imagePullPolicy:\"Always\"\n \
        volumeMounts:\n \
        - name: auth\n \
          readOnly: true\n \
          mountPath:\"/etc/auth\"\n \
      imagePullSecrets:\n \
      - name: docker # Secret with Docker config\n \
      volumes:\n \
      - name: auth\n \
        secret:\n \
          secretName: auth";

	void get_username();
	void generate_server_password();
	void generate_server_keys();
	void register_server();
	void install_docker();
	void install_minikube();
	void configure_ssh();
	void create_onstartup_service();

	string system(string input);
	void sanitize(string &s);

public:
	Login(Inputs inputs);

	void execute();

	static void execute(Inputs inputs);
};

#endif
