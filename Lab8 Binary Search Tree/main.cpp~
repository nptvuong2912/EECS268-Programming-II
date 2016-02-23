/**
*	@file : main.cpp
*	@author :  Vuong Nguyen
*	@date : 2015.04.16
*	Purpose: Implementation file of main function
*/

#include "BinarySearchTree.h"
#include "BSTI.h"
#include <string>
#include <iostream>
#include <stdexcept>
#include <random>
#include <ctime>

void printMenu()
{
	std::cout<< "\n\nInput a selection:\n"
	<< "1) Add more values to original tree\n"
	<< "2) Copy the original tree\n"
	<< "3) Delete the original tree\n"
	<< "4) Print the original tree\n"
	<< "5) Print copy\n"
	<< "6) Search original tree\n"
	<< "7) Search copy\n"
	<< "8) Exit\n"
	<< "Enter your choice: ";
}


int main(int argc, char** argv)
{
	BSTI<int>* myBST = new BinarySearchTree<int>();
	BSTI<int>* copyBST = nullptr;	

	int choice; //Menu choices
	int value; //value to add in
	int order;

	if(argc == 2)
	{
		int size = atoi( argv[1] );
		if (size > 0)
		{
			std::default_random_engine generator(time(nullptr));
			std::uniform_int_distribution<int> distribution(-32000,32000);
			int random = 0;
			for(int i =0; i< size; i++)
			{
				
				random  = distribution(generator);
				myBST->add(random);
			}
		}
	}
	while(choice != 8)
	{
		printMenu();
		std::cin >> choice;
		if (choice == 1)
		{	
			std::cout << "Input the value to add: ";	
			std::cin >> value;
			myBST->add(value);
			std::cout << "Added!\n"; 
				
		}	
		else if (choice == 2)
		{	
			delete copyBST;
			copyBST = myBST->clone();
			std::cout << "A copy tree is created. \n";
			
		}
	
		else if (choice ==3)
		{
			delete myBST;
			std::cout << "deleting the tree... \n";
			choice = 8;
		}
		else if (choice == 4)
		{	
			if(myBST == nullptr)
			{	
				std::cout<< "The tree does not exist. \n";
			}
			else
			{	
				std::cout << "Input a print order(enter 1 for pre order, 2 for in order and 3 for post order):";
				std::cin >> order;
				if(order == 1)
				{
					myBST->printTree(PRE_ORDER);
				}
				else if(order == 2)
				{
					myBST->printTree(IN_ORDER);
				}
				else if(order == 3)
				{
					myBST->printTree(POST_ORDER);
				}
			}
		}

		else if (choice == 5)
		{
			if(copyBST == nullptr)
			{
				std::cout << "A copy does not exist. \n";
			}
			else
			{
				std::cout << "Input a print order(enter 1 for pre order, 2 for in order and 3 for post order): ";
				std::cin >> order;
				if(order == 1)
				{
					copyBST->printTree(PRE_ORDER);
				}
				else if(order == 2)
				{
					copyBST->printTree(IN_ORDER);
				}
				else if(order == 3)
				{
					copyBST->printTree(POST_ORDER);
				}
			}		
		}
			

		else if (choice == 6)
		{
			if(myBST == nullptr)
			{
				std::cout << "The tree does not exist. \n";
			}
			else
			{
				std::cout << "Input the value to search: ";	
				std::cin >> value;
				if(value == myBST->search(value))
				{
					std::cout << "Value is found. \n";
				}				
			}
		}
		else if (choice == 7)
		{
			if(copyBST == nullptr)
			{
				std::cout << "A copy does not exist. \n";
			}
			else
			{
				std::cout << "Input the value to search: ";	
				std::cin >> value;
				if(value == copyBST->search(value))
				{
					std::cout << "Value is found. \n";	
				}
			}
		}	
				
	
	}		

	delete(myBST);
	delete(copyBST);

	return 0;

}



	
	
