/**
*	@file : SortDriver.h
*	@author : Vuong Nguyen
*	@date : 2015.04.08
*	Purpose: Header file of SortDriver class
*/

#ifndef SORTDRIVER_H
#define SORTDRIVER_H
#include <string>
#include <iostream>
#include <fstream>

class SortDriver
{
	public:
	/**
	*  @pre a valid 2D array and the arguments contained within are valid
	*  @post creates a file containing the timing info
	*  @return None
	*/
    	static void run(int argc, char** argv);

	/**
	*  @pre none
	*  @post prints the menu to help the suer use the NumberFileGenerator
	*  @return None
	*/
	static void printHelpMenu();

	private:
	/**
	*  @pre The input file is created by a NumberFileGenerator
	*  @post None
	*  @return True if the file exists, false otherwise.
	*/
	static bool isFileAccessible(std::string fileName);

	/**
	*  @pre None
	*  @post None
	*  @return True if the sort parameter matches a valid one
	*/
	static bool isSortValid(std::string sortParameter);

	/**
	*  @pre None
	*  @post None
	*  @return True if the file specified by inputFileName exists and the sort parameter is valid
	*/
	static bool areParameterValid(std:string sortName, std::string inputFileName);

	/**
	*  @pre the input file was created in NumberFileGenearator
	*  @post the first line of the file is read in, containing the count
	*  @return  how many numbers are in the file
	*/
	static int getFileCount(std::ifstream& inputFile);

	/**
	*  @pre the input file was created in NumberFileGenearator, size was read in and that size if correct
	*  @post the remainder of input file numbers are read in. File is not closed
	*  @return  a pointer to a new array containing the values from the input file.
	*/
	static int* createArray(std::ifstream& inputFile, int size);

	/**
	*  @pre Original and copy are valid arrays of the correct size
	*  @post all the values are copied to the copy
	*  @return  none
	*/
	static void copyArray(int original[], int copy[], int size);
};

#endif









