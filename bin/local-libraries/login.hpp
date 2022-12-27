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
#include "../global-libraries/bin/inputs.hpp"
#include "memory.hpp"

// using ...
using namespace std;

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

#endif
