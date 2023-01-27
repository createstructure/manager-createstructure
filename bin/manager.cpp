// Dependencies
#include <bits/stdc++.h>
#include "global-libraries/bin/inputs.hpp"
#include "local-libraries/help.hpp"
#include "local-libraries/version.hpp"
#include "local-libraries/login.hpp"

// using ...
using namespace std;

// Definitions
//#define DEBUG

int main(int argc, char *argv[])
{
	Inputs inputs(argc, argv);

	if (inputs.exist("--help"))
	{
		Help::execute(inputs);
	}
	else if (inputs.exist("--version"))
	{
		Version::execute(inputs);
	}
	else if (inputs.exist("--login"))
	{
		Login::execute(inputs);
	}
	else
	{
		// Default
#ifdef DEBUG
		cout << "Default option" << endl;
#endif // DEBUG
		Help::execute(inputs);
	}

	return 0;
}

#undef DEBUG