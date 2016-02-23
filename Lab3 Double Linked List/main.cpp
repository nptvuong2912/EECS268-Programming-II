
/**
*	@file : main.cpp
*	@author :  Vuong Nguyen
*	@date : 2015.02.25
*	Purpose: Implementation file of main function
*/

#include "Node.h"
#include "DoubleLinkedList.h"
#include <string>
#include <iostream>
#include <stdexcept>

void printMenu()
{
	std::cout << 	"\n\nMake choice\n"
		<<	"1) push value onto front\n"
		<<	"2) push value onto back\n"
		<<	"3) insert behind a value\n"
		<<	"4) insert ahead of a value\n"
		<<	"5) remove value\n"
		<<	"6) print list\n"
		<<	"7) Quit\n"
		<< 	"Your choice: ";
}
	
int main()
{
	DoubleLinkedList<int>* DLL = new DoubleLinkedList<int>();

	int answer = 0;
	int value = 0;
	int chosenValue = 0;

	while (answer != 7)
	{
		
		printMenu();
	
		std::cin >> answer;

		if(answer == 1)
		{	
			std::cout << "Input a value: ";
			std::cin >> value;
			DLL->pushFront(value);
		}
		if(answer == 2)
		{
			std::cout << "Input a value: ";
			std::cin >> value;
			DLL->pushBack(value);
		}
		if (answer == 3)
		{
			std::cout << "Choose a value in the list: ";
			std::cin >> chosenValue;
			std::cout << "Input a new value: ";
			std::cin >> value;
			try
			{
				DLL->insertBehind(chosenValue, value);
			}
			catch(std::runtime_error& e)
			{
				std::cout<<e.what();
			}	
	
		}
		if(answer == 4)
		{
			std::cout << "Choose a value in the list: ";
			std::cin >> chosenValue;
			std::cout << "Input a new value: ";
			std::cin >> value;
			try
			{
				DLL->insertAhead(chosenValue, value);
			}
			catch(std::runtime_error& e)
			{
				std::cout<<e.what();
			}
		}

		if (answer == 5)
		{
			std::cout << "Input a value: ";
			std::cin >> value;
			DLL->remove(value);
		}

		if (answer == 6)
		{
			DLL->printList();
		}

		if (answer == 7)
		{
			delete DLL;
		}
	}
	
	return 0;

}
