/**
*	@file : NumberFileDriver.cpp
*	@author : Vuong Nguyen
*	@date : 2015.04.08
*	Purpose: Implement file of Numberfile Driver class
*/


#include "NumberFileDriver.h"
#include <iostream>
#include <string>
#include "NumberFileGenerator.h"

void NumberFileDriver::run(int argc, char** argv)
{
	std::string type = argv[2];
	if(isValidOption(type))
	{

		int ammount = std::stoi(argv[4]);
		int value1 = std::stoi(argv[5]);
		int value2 = std::stoi(argv[6]);

		if(type == "-a")
		{
			NumberFileGenerator::ascending(argv[3], ammount );
		}
		else if(type == "-d")
		{
			NumberFileGenerator::descending(argv[3], ammount );
		}
		else if(type == "-s")
		{
			NumberFileGenerator::singleValue(argv[3], ammount , value1 );
		}
		else if(type == "-r")
		{
			NumberFileGenerator::random(argv[3], ammount , value1 , value2 );
		}
		else
			printHelpMenu();
		
	}
}

void NumberFileDriver::printHelpMenu()
{
	std::cout << "\nUse Number File Generator in one of the following ways:\n\n"
			<< "./prog -create -a filename amount\n"
			<< "./prog -create -d filename amount\n"
			<< "./prog -create -s filename amount value\n"
			<< "./prog -create -r filename amount min max\n"
			<< "Option explainations:\n"
			<< "\t-a for ascending\n"
			<< "\t-d for descending\n"
			<< "\t-s for a single value\n"
			<< "\t-r for random values\n"
			<< "\tfilename is the ouput file name\n"
			<< "\tamount is the amount of random numbers to place in the file\n"
			<< "\tvalue is the single number that will be written to file in -s mode\n"
			<< "\tmin is the low end of the range of random numbers\n"
			<< "\tmax is the high end (non-inclusive) of the range of random numbers\n";

}
 
bool NumberFileDriver::isValidOption(std::string option)
{
	if(option == "-a" || option == "-d" || option == "-s" ||option == "-r")
	{
		return true;
	}
	else
		printHelpMenu();
}








