/**
 * @file help.cpp
 *
 * @brief Library to manage help messages
 *
 * @author Davide Castellani (@DavideC03)
 */

// Dependencies
#include "help.hpp"

// Definitions
// #define DEBUG

// Function(s)
/**
 * @brief Construct a new Help:: Help object
 * 
 * @param inputs all the inputs given by command-line
 */
Help::Help(Inputs inputs)
{
	Help::inputs = inputs;
}

/**
 * @brief Execute help, open man documentation
 */
void Help::execute()
{
	system("man manager"); // Open the package manual
}

/**
 * @brief Execute help, without inizialization
 * 
 * @param inputs 
 */
void Help::execute(Inputs inputs)
{
	Help Help(inputs);
	Help.execute();
}

#undef DEBUG
