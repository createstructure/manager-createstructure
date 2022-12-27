/**
 * help.cpp
 *
 * Library to manage help messages
 *
 * @author Davide Castellani (@DavideC03)
 */

// Dependencies
#include "help.hpp"

// Definitions
// #define DEBUG


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
