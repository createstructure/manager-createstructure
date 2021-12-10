/**
 * vesion.hpp
 *
 * Library to get the version of the program
 *
 * @author Davide Castellani (@DavideC03)
 */

#ifndef VERSION
// If not imported yet
#define VERSION

// Dependencies
#include <bits/stdc++.h>
#include "../global-libraries/bin/inputs.hpp"

// using ...
using namespace std;

// Definitions
// #define DEBUG

// Classes prototipe(s)
class Version
{
private:
	Inputs inputs;

public:
	Version(Inputs inputs);

	void execute();

	static void execute(Inputs inputs);
};

// Function(s)
Version::Version(Inputs inputs)
{
	/**
	 * Constructor
	 * 
	 * @param inputs Inputs object
	 */
	Version::inputs = inputs;
}

void Version::execute()
{
	/**
	 * Execute
	 */
	system("dpkg --status manager | grep ^Version | sed 's/Version: //'"); // Returns the package version
}

void Version::execute(Inputs inputs)
{
	/**
	 * Execute
	 * 
	 * @param inputs Inputs object
	 */
	Version Version(inputs);
	Version.execute();
}

#undef DEBUG
#endif
