// Dependencies
#include <bits/stdc++.h>
#include "global-libraries/bin/inputs.hpp"
#include "local-libreries/help.hpp"
#include "local-libreries/version.hpp"
#include "local-libreries/login.hpp"

// using ...
using namespace std;

// Definitions
#define DEBUG

int main(int argc, char *argv[])
{
	Inputs inputs(argc, argv);

	if (inputs.exist("--help"))
	{
		Help::execute(inputs);
		return 0;
	}

	if (inputs.exist("--version"))
	{
		Version::execute(inputs);
		return 0;
	}

	if (inputs.exist("--login"))
	{
		Login::execute(inputs);
		return 0;
	}

	return 0;
}

#undef DEBUG