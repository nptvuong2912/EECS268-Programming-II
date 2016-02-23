/**
*	@file : main.cpp
*	@author :  Vuong Nguyen
*	@date : 2015.03.03
*	Purpose: Implementation file of main function
*/

#include "Node.h"
#include "Stack.h"
#include "StackInterface.h"
#include <string>
#include <iostream>
#include <stdexcept>

void printMenu()
{
	std::cout<< "\n\nSelect an action:\n"
	<< "1) Add something to stack 1\n"
	<< "2) Add something to stack 2\n"
	<< "3) See what is at the top of stack 1\n"
	<< "4) See what is at the top of stack 2\n"
	<< "5) Print contents in stack 1\n"
	<< "6) Print contents in stack 2\n"
	<< "7) Remove something from stack 1\n"
	<< "8) Remove something from stack 2\n"
	<< "9) Compare Stacks\n"
	<< "10) Quit\n"
	<< "Enter choice: ";
}

template <typename T>
void compareStacks(const StackInterface<T>& s1, const StackInterface<T>& s2)
{
	std::cout 	<< "\nComparison of stacks:\n"
			<< "lane 1 < lane 2: " <<  (s1 <  s2) 	<< "\n"
			<< "lane 1 > lane 2: " <<  (s1 >  s2) 	<< "\n"
			<< "lane 1 >= lane 2: " << (s1 >= s2) 	<< "\n"
			<< "lane 1 <= lane 2: " << (s1 <= s2) 	<< "\n"
			<< "lane 1 == lane 2: " << (s1 == s2) 	<< "\n"
			<< "lane 1 != lane 2: " << (s1 != s2) 	<< "\n";
}

int main()
{
	StackInterface<std::string>* lane1 = new Stack<std::string>();
	StackInterface<std::string>* lane2 = new Stack<std::string>();

	int answer = 0;
	std::string newWord;
	while (answer != 10)
	{
		printMenu();
	
		std::cin >> answer;

		if(answer == 1)
		{	
			std::cout << "Input a new word to Stack 1: ";
			std::cin >> newWord;
			lane1->push(newWord);
		}
		if(answer == 2)
		{
			std::cout << "Input a new word to Stack 2: ";
			std::cin >> newWord;
			lane2->push(newWord);
		}		
		if (answer == 3)
		{
			
			try
			{
				std::cout << "The top of stack 1 is: " <<lane1->peek();
				
			}
			catch(PreconditionViolationException &e)
			{
				std::cout<<e.what();
			}	
	
		}
		if(answer == 4)
		{
			try
			{
				std::cout << "The top of stack 2 is: " <<lane2->peek();	
			}
		
			catch(PreconditionViolationException &e)
			{
				std::cout<<e.what();
			}		
		}
		if (answer == 5)
		{
			lane1->print();		
		}
		if (answer == 6)
		{
			lane2->print();
		}

		if (answer == 7)
		{
			std::cout << "Removing the top of stack 1... ";
			try
			{
				lane1->pop();
			}
			catch(std::runtime_error& e)
			{
				std::cout<<e.what();
			}
		}
		if(answer == 8)
		{
			std::cout << "Removing the top of stack 2... ";
			try
			{
				lane2->pop();
			}
			catch(std::runtime_error& e)
			{
				std::cout<<e.what();
			}
		}
		if(answer == 9)
		{
			std::cout << "Comparison of stacks: \n";
			compareStacks(*lane1, *lane2);

		}
	}
	delete (lane1);
	delete (lane2);

	return 0;
}

