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
	string SERVICE = "[Unit]\n\
Description=Start minikube\n\
After=docker.service\n\
\n\
[Service]\n\
ExecStart=minikube start\n\
Type=oneshot\n\
RemainAfterExit=yes\n\
User=$(logname)\n\
TimeoutSec=0\n\
\n\
[Install]\n\
WantedBy=default.target\n\
\n\
";

	string KUBERNATES_CONFIG = "apiVersion: apps/v1\n\
kind: ReplicaSet\n\
metadata:\n\
  name: manager\n\
  labels:\n\
    app: manager\n\
spec:\n\
  replicas: 1 # Number of replicas\n\
  selector:\n\
    matchLabels:\n\
      app: core\n\
  template:\n\
    metadata:\n\
      name: core\n\
      labels:\n\
        app: core\n\
    spec:\n\
      containers:\n\
      - name: core\n\
        image: ghcr.io/createstructure/core-createstructure:beta # latest if stable, beta otherwise\n\
        imagePullPolicy: \"IfNotPresent\"\n\
        volumeMounts:\n\
        - name: auth\n\
          readOnly: true\n\
          mountPath: \"/etc/auth\"\n\
      imagePullSecrets:\n\
      - name: docker # Secret with Docker config\n\
      volumes:\n\
      - name: auth\n\
        secret:\n\
          secretName: auth\n";

	string SERVICE_VENTILATION = "[Unit]\n\
Description=Manage ventilation\n\
\n\
[Service]\n\
ExecStart=/usr/local/bin/ventilation.sh\n\
Type=simple\n\
TimeoutSec=0\n\
\n\
[Install]\n\
WantedBy=default.target\n\
\n\
";

	string VENTILATION = "#!/bin/bash\n\
\n\
# Check sudo\n\
if [ \"$EUID\" -ne 0 ]\n\
  then echo \"Please run as root\";\n\
  exit;\n\
fi\n\
\n\
# Common path for all GPIO access\n\
BASE_GPIO_PATH=/sys/class/gpio;\n\
\n\
# GPIO pin\n\
PIN=14;\n\
\n\
# Temperature to turn on/off\n\
TURN_ON=50;\n\
TURN_OFF=40;\n\
\n\
# Assign names to states\n\
HIGH=\"1\";\n\
LOW=\"0\";\n\
\n\
# Setup\n\
function setup()\n\
{\n\
    setupPinOutput $PIN;\n\
}\n\
\n\
# Setup a pin as output\n\
function setupPinOutput()\n\
{\n\
    if [ ! -e $BASE_GPIO_PATH/gpio$1 ]; then\n\
        echo \"$1\" > $BASE_GPIO_PATH/export;\n\
    fi\n\
\n\
    echo \"out\" > $BASE_GPIO_PATH/gpio$1/direction;\n\
}\n\
\n\
# Change status on a pin\n\
function writePin()\n\
{\n\
    sudo echo $2 > $BASE_GPIO_PATH/gpio$1/value;\n\
}\n\
\n\
# Get CPU temperature as int\n\
function temperature()\n\
{\n\
    echo $(bc <<< \"$(cat /sys/class/thermal/thermal_zone0/temp)/1000\")\n\
}\n\
\n\
# Run setup\n\
setup;\n\
\n\
# Loop forever until user presses Ctrl-C\n\
while [ 1 ]\n\
do\n\
    # Read temperature\n\
    t=$(temperature);\n\
    echo $t\n\
\n\
    if [ \"$t\" -ge \"$TURN_ON\" ]; then\n\
        writePin $PIN $HIGH;\n\
    fi\n\
\n\
    if [ \"$t\" -le \"$TURN_OFF\" ]; then\n\
        writePin $PIN $LOW;\n\
    fi\n\
\n\
    sleep 10;\n\
done\n\
\n\
";

	void get_username();
	void generate_server_password();
	void generate_server_keys();
	void register_server();
	void install_docker();
	void install_minikube();
	void configure_ssh();
	void create_onstartup_service();
  bool get_if_raspberry();

	string system(string input);
	void sanitize(string &s);

public:
	Login(Inputs inputs);

	void execute();

	static void execute(Inputs inputs);
};

#endif
