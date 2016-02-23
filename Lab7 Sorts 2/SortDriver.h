/**
*	@file : SortDriver.h
*	@author : Vuong Nguyen
*	@date : 2015.04.08
*	Purpose: Header file of Sort Driver class
*/

#include <ctime>
#include <string>
#include <fstream>
#include <cassert>

#ifndef SORTDRIVER_H
#define SORTDRIVER_H

class SortDriver
{
	public:
	/**
	*  @pre arguments is a valid 2D array and the arguments contained within are valid
	*  @post The file is created containing the timing information
	*  @return None
	*/
    	static void run(int argc, char** argv);
	
	/**
	*  @pre None
	*  @post prints a menu to help the user use the NumberFileGenerator
	*  @return None
	*/
    	static void printHelpMenu();

	private:
	/**
	*  @pre the input file was created by a NumberFileGenerator
	*  @post None
	*  @return true if the file exists
	*/
    	static bool isFileAccessible(std::string fileName);

	/**
	*  @pre None
	*  @post None
	*  @return true if the sort parameter matches a valid one
	*/
    	static bool isSortValid(std::string sortParameter);

	/**
	*  @pre None
	*  @post None
	*  @return true if the file specified by inputFileName exists and the sort parameter is valid.
	*/
    	static bool areParametersValid(std::string sortName, std::string inputFileName);

	/**
	*  @pre file was created with the NumberFileGenerator
	*  @post the first line of the file is read in, containing the count
	*  @return how many numbers are in the line
	*/
	static int getFileCount(std::ifstream& inputFile);

	/**
	*  @pre the input file was ccreated with the NumberFileGenerator, the size was read in, and size if correct
	*  @post the remainder of input file numbers are read in.
	*  @return a pointer to a new array containing the value from the input file
	*/
	static int* createArray(std::ifstream& inputFile, int size);

	/**
	*  @pre Original and copy are valid of the correct size
	*  @post all values from the original are copied
	*  @return None
	*/
	static void copyArray(int original[], int copy[], int size);
};

#endif


