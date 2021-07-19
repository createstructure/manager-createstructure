// Dependencies
#include <bits/stdc++.h>
#include "libraries/bin/json.hpp"
//#include "libraries/bin/createstructure.hpp"
#include "libraries/bin/createstructure_memory.hpp"
#include "libraries/bin/createstructure_work.hpp"
#include "libraries/bin/createstructure_rest.hpp"
#include "libraries/bin/createstructure_inputs.hpp"
#include "libraries/bin/createstructure_help.hpp"

// using ...
using namespace std;
using json = nlohmann::json;

// Definitions
//#define DEBUG
//#define VIEW_OUTPUT // View the docker output
//#define ONCE

#ifdef DEBUG
#define VIEW_OUTPUT
#endif // DEBUG

// Declared functions
void eraseAllSubStr(string &mainStr, const string toErase);
int main(int argc, char *argv[]);

void eraseAllSubStr(string &mainStr, const string toErase)
{
	/* Decode Work: get decoded work instructions
         *
         * output:
         *      - decoded work instructions
		 *   
         * output:
         *      - decoded work instructions
         */
	size_t pos = string::npos;
	while ((pos = mainStr.find(toErase)) != string::npos)
		mainStr.erase(pos, toErase.length());
}

// Code
int main(int argc, char *argv[])
{
	/* Main: the start point of the code
	 *
	 * inputs:
	 * 	- argc: the number of command-line arguments
	 *	- argv: an array containing all command-line arguments
 	 *
	 * output:
	 *	- a run code: if it works in the correct way it will return 0
	 */
	cout << "Started manager" << endl;

	// Check inputs
	inputs in(argc, argv);
	help h(in, "manager");

	// Function variable(s)
	int i = 0;

#ifndef ONCE
	while (true)
	{
#endif // ONCE

		waitUntilOkMemory();

		// Get data
		json jData = getWork();
		string data = jData["data"].dump();
#ifdef DEFAULT
		cout << data << endl;
#endif // DEFAULT
		eraseAllSubStr(data, "\\u0000");

		// Run job
		system(
			(
				string("docker run ghcr.io/createstructure/core-createstructure '") +
				data +
#ifdef VIEW_OUTPUT
				"' &"
#else  // VIEW_OUTPUT
			"' > /dev/null &"
#endif // VIEW_OUTPUT
				)
				.c_str());
		cout << "Runned process n°" << i++ << endl;

		// Set work as finished
		json finishJson;
		finishJson["server_id"] = jData["data"]["server_id"].get<string>();
		finishJson["server_code"] = jData["data"]["server_code"].get<string>();
		finishJson["work_id"] = jData["data"]["work_id"].get<string>();
		string link("https:\u002F\u002Fwww.castellanidavide.it/other/rest/product/started_work.php");
		request(link, "", finishJson, "POST");
		sleep_for(500ms);
#ifndef ONCE
	}
#endif // ONCE

	return 0;
}
