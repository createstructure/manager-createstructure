/**
 * version.hpp
 *
 * Library to get the version of the program
 *
 * @author Davide Castellani (@DavideC03)
 */

#ifndef VERSION
// If not imported yet
#define VERSION

// Dependencies
#include "../global-libraries/bin/inputs.hpp"

// using ...
using namespace std;

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

#endif
