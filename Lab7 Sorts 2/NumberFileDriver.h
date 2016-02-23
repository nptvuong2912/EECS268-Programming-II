/**
*	@file : NumberFileDriver.h
*	@author : Vuong Nguyen
*	@date : 2015.04.08
*	Purpose: Header file of Number File Driver class
*/

#include <ctime>
#include <string>
#include <fstream>

#ifndef NUMBERFILEDRIVER_H
#define NUMBERFILEDRIVER_H

class NumberFileDriver
{
	public:
	/**
	*  @pre arguments is a valid 2D array and the arguments contained within are valid
	*  @post The number file is created following the specifications. Otherwise print the menu
	*  @return None
	*/
    	static void run(int argc, char** argv);

	/**
	*  @pre None
	*  @post prints a menu to help the user.
	*  @return None
	*/
    	static void printHelpMenu();

	private:
	/**
	*  @pre None
	*  @post print the menu to help the user use NumberFileGenerator
	*  @return true if the option passed in is valid
	*/
    	static bool isValidOption(std::string option);
};

#endif
