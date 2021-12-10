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
#include <bits/stdc++.h>
#include "../global-libraries/bin/inputs.hpp"

// using ...
using namespace std;

// Definitions
// #define DEBUG

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

// Function(s)
Help::Help(Inputs inputs)
{
	/**
	 * Constructor
	 * 
	 * @param inputs Inputs object
	 */
	Help::inputs = inputs;
}

void Help::execute()
{
	/**
	 * Execute
	 */
	system("man manager"); // Open the package manual
}

void Help::execute(Inputs inputs)
{
	/**
	 * Execute
	 * 
	 * @param inputs Inputs object
	 */
	Help Help(inputs);
	Help.execute();
}

#undef DEBUG
#endif
