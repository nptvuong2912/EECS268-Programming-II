/**
*	@file : main.cpp
*	@author : Vuong Nguyen
*	@date : 2015.04.02
*	Purpose: Implementation of main function
*/

#include "Sorts.h"
#include <iostream>
#include <string>
#include <chrono>
#include <cassert>
#include <ctime>
#include <random>

void printMenu()
{
	std::cout 	<< "\n\nSelect a sort:\n"
			<< "1) Bubble Sort\n"
			<< "2) Insertion Sort\n"
			<< "3) Selection Sort\n"
			<< "4) Bogo Sort (use only with very small arrays!)\n"
			<< "Enter choice: ";
}

void printArray(int* arr, int size) //method to print the array
{
	for(int i =0; i<size; i++)
	{
		std::cout << arr[i] << ", ";
	}
	std::cout << "\n";
}		

int* createRandomIntArray(int size, int min, int max)
{
	int* arr = new int[size];
	std::default_random_engine generator(time(nullptr));
	std::uniform_int_distribution<int> distribution(min,max);
	for (int i = 0; i < size; i++)
	{
		arr[i] = distribution(generator);
	}
	return arr;
}

int main()
{
	char quit; //ask the user to quit or not
	char print; //ask the user to print the array
	int choice; //sort options
	int size; //ask for size of the array
	int lowerBound; //input the bounds of the array
	int upperBound;

	Sorts<int> sorts = Sorts<int>();
	
	std::chrono::system_clock::time_point start;
	std::chrono::system_clock::time_point end;
	std::chrono::duration<double> elapsed;

	 
	while (quit != 'y')
	{
		printMenu();
		std::cin >> choice;

		std::cout << "Input a size for the random array: " << std::endl;
		std::cin >> size;

		std::cout << "Input a lower bound on the range of random numbers: " <<std::endl;
		std::cin >> lowerBound;

		std::cout << "Input an upper bound on the range of random numbers: "<< std::endl;
		std::cin >> upperBound;
	
		//creates the array 
		int* arr = createRandomIntArray(size, lowerBound, upperBound);

		std::cout << "Do you want to print the unsorted array? (y/n)" << std::endl;
		
		std::cin >> print;

		if (print == 'y')
		{
			std::cout<< "Here is your unsorted array: \n";
			printArray(arr, size);
		}
		
			if (choice == 1)
			{
				start = std::chrono::system_clock::now();
				sorts.bubbleSort(arr, size);
				end = std::chrono::system_clock::now();
				elapsed = (end - start);
				std::cout<< "Sorting with bubble sort...\n";
				std::cout<< "Do you want to print the sorted array? (y/n):" << std::endl;
				std::cin >> print;
				if (print == 'y')
				{
					std::cout<< "Here is your sorted array: \n";
					printArray(arr, size);
				}
				std::cout << size << " numbers were sorted with Bubble Sort in " << elapsed.count() << " seconds\n";	
		
			}
			else if (choice == 2)
			{
				start = std::chrono::system_clock::now();
	
				sorts.insertionSort(arr, size);
				end = std::chrono::system_clock::now();
				elapsed = (end - start);
				std::cout<< "Sorting with insertion sort...\n";
				std::cout<< "Do you want to print the sorted array? (y/n):" << std::endl;
				std::cin >> print;
				if (print == 'y')
				{
					std::cout<< "Here is your sorted array: \n";
					printArray(arr, size);
					
				}
				std::cout << size << " numbers were sorted with insertion Sort in " << elapsed.count() << " seconds\n";

			}
			else if (choice == 3)
			{
				start = std::chrono::system_clock::now();
				sorts.selectionSort(arr, size);
				end = std::chrono::system_clock::now();
				elapsed = (end - start);
				std::cout<< "Sorting with selection sort...\n";
				std::cout<< "Do you want to print the sorted array? (y/n):" << std::endl;
				std::cin >> print;
				if (print == 'y')
				{
					std::cout<< "Here is your sorted array: \n";
					printArray(arr, size);
				}
				std::cout << size << " numbers were sorted with selection Sort in " << elapsed.count() << " seconds\n";	
			}
			else if (choice == 4)
			{
				start = std::chrono::system_clock::now();
				sorts.bogoSort(arr, size);
				end = std::chrono::system_clock::now();
				elapsed = (end - start);
				std::cout<< "Sorting with bogo sort...\n";
				std::cout<< "Do you want to print the sorted array? (y/n):" << std::endl;
				std::cin >> print;
				if (print == 'y')
				{
					std::cout<< "Here is your sorted array: \n";
					printArray(arr, size);
				}
				std::cout << size << " numbers were sorted with bogo Sort in " << elapsed.count() << " seconds\n";	
			}
	
			std::cout << "Do you want to quit?(y/n): ";
			std:: cin >> quit;
		
			
			
		delete[]arr;
	}	
		
	return 0;
}








	
