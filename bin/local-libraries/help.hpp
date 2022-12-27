/**
 * help.hpp
 *
 * Library to manage help messages
 *
 * @author Davide Castellani (@DavideC03)
 */

#ifndef HELP
// If not imported yet
#define HELP

// Dependencies
#include "../global-libraries/bin/inputs.hpp"

// using ...
using namespace std;

// Classes prototipe(s)
class Help
{
private:
	Inputs inputs;

public:
	Help(Inputs inputs);

	void execute();

	static void execute(Inputs inputs);
};

#endif
