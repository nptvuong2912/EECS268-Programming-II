/**
*	@file : NumberFileGenerator.cpp
*	@author : Vuong Nguyen
*	@date : 2015.04.08
*	Purpose: Implement file of Number File generator class
*/


#include "NumberFileGenerator.h"
#include <iostream>
#include <string>

void NumberFileGenerator::ascending(std::string fileName, int amount)
{
	std::ofstream myOutputFile(fileName);
	if (amount > 0 && myOutputFile.good())
	{
		myOutputFile << amount << "\n";
		for (int i = 1; i <= amount; i++)
		{
			myOutputFile << i << "\n";
		}
	}
	std::cout << amount << " numbers stored. \n";
}

void NumberFileGenerator::descending(std::string fileName, int amount)
{
	std::ofstream myOutputFile(fileName);
	if (amount > 0 && myOutputFile.good())
	{
		myOutputFile << amount << "\n";
		for (int i = amount; i > 0; i--)
		{
			myOutputFile << i << "\n";
		}
	}
	std::cout << amount << " numbers stored. \n";
}

void NumberFileGenerator::random(std::string fileName, int amount, int min, int max)
{
	std::ofstream myOutputFile(fileName);
	if (amount > 0 && myOutputFile.good())
	{
		myOutputFile << amount << "\n";
		std::default_random_engine generator(time(nullptr));
		std::uniform_int_distribution<int> distribution(min,max);
		for (int i = 0; i < amount; i++)
		{
			myOutputFile << distribution(generator) << "\n";
		}
	}
	std::cout << amount << " numbers stored. \n";
}

void NumberFileGenerator::singleValue(std::string fileName, int amount, int value)
{
	std::ofstream myOutputFile(fileName);
	if (amount > 0 && myOutputFile.good())
	{
		myOutputFile << amount << "\n";
		for (int i = 0; i< amount; i++)
		{
			myOutputFile << value << "\n";
		}
	}
	std::cout << amount << " numbers stored. \n";
}
