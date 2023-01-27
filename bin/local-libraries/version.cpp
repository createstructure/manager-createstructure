/**
 * @file version.cpp
 *
 * @brief Library to get the version of the program
 *
 * @author Davide Castellani (@DavideC03)
 */

// Dependencies
#include "version.hpp"

// Definitions
// #define DEBUG

// Function(s)
/**
 * @brief Construct a new Version:: Version object
 * 
 * @param inputs all the inputs given by command-line
 */
Version::Version(Inputs inputs)
{
	Version::inputs = inputs;
}

/**
 * @brief Execute version, give the current version of the application
 */
void Version::execute()
{
	system("dpkg --status manager | grep ^Version | sed 's/Version: //'"); // Returns the package version
}

/**
 * @brief Execute version, without inizialization
 */
void Version::execute(Inputs inputs)
{
	Version Version(inputs);
	Version.execute();
}

#undef DEBUG
