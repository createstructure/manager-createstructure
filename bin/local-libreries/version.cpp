/**
 * veesion.cpp
 *
 * Library to get the version of the program
 *
 * @author Davide Castellani (@DavideC03)
 */

// Dependencies
#include "version.hpp"

// Definitions
// #define DEBUG

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
