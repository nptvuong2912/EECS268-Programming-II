/**
*	@file : main.cpp
*	@author : Vuong Nguyen
*	@date : 2015.04.09
*	Purpose: Implementation of main function
*/

#include "Sorts.h"
#include "SortDriver.h"
#include "NumberFileGenerator.h"
#include "NumberFileDriver.h"
#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
#include <random>
#include <fstream>

int main(int argc, char** argv)
{
	NumberFileDriver* myFileDriver = new NumberFileDriver();
	SortDriver* mySortDriver = new SortDriver();	

	if(argc <5)
	{
		std::cout << "There must be at least 5 command line arguments.\n";
	}
	else if (argc >=5)
	{
		std::string mode = argv[1];
		if (mode == "-create")
		{
			myFileDriver->run(argc, argv);		
		}
		
		else if (mode == "-sort")
		{
			mySortDriver->run(argc, argv);
		}
		else
		{
			myFileDriver->printHelpMenu();
			mySortDriver->printHelpMenu();
		}
	}
	delete myFileDriver;
	delete mySortDriver;
	return 0;
}
