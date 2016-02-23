
/**
*	@file : SortDriver.cpp
*	@author : Vuong Nguyen
*	@date : 2015.04.08
*	Purpose: Implement file of Sort Driver class
*/


#include "SortDriver.h"
#include <iostream>
#include <string>
#include "Sorts.h"

void SortDriver::run(int argc, char** argv)
{
	if(areParametersValid(argv[2], argv[3]))
	{
		std::ifstream myInputFile(argv[3]);
		std::ofstream myOutputFile(argv[4]);

		int fileCount = getFileCount(myInputFile);
		int* numArray = createArray(myInputFile, fileCount);
		
		std::string sort = argv[2];
		if(sort == "-bubble")
		{
			std::cout << "Calculating sort timing information... \n";

			double timeBubble = Sorts<int>::sortTimer(Sorts<int>::bubbleSort, numArray, fileCount);
			myOutputFile << "Bubble Sort sort " <<  fileCount << " numbers in " << timeBubble << " seconds\n";
			std::cout << "Calculations finshed. Results stored. \n";
			std::cout << "Exiting...";
			
		}
		else if(sort == "-selection")
		{
			std::cout << "Calculating sort timing information... \n";
			double timeSelection = Sorts<int>::sortTimer(Sorts<int>::selectionSort, numArray, fileCount);
			myOutputFile << "Selection Sort sort " <<  fileCount << " numbers in " << timeSelection << " seconds\n";
			std::cout << "Calculations finshed. Results stored. \n";
			std::cout << "Exiting...";

		}
		else if(sort == "-insertion")
		{
			std::cout << "Calculating sort timing information... \n";
			double timeInsertion = Sorts<int>::sortTimer(Sorts<int>::insertionSort, numArray, fileCount);
			myOutputFile << "Insertion Sort sort " <<  fileCount << " numbers in " << timeInsertion << " seconds\n";
			std::cout << "Calculations finshed. Results stored. \n";
			std::cout << "Exiting...";

		}
		else if(sort == "-quick")
		{
			std::cout << "Calculating sort timing information... \n";
			double timeQuick = Sorts<int>::sortTimer(Sorts<int>::quickSort, numArray, fileCount);
			myOutputFile << "Quick Sort sort " <<  fileCount << " numbers in " << timeQuick << " seconds\n";
			std::cout << "Calculations finshed. Results stored. \n";
			std::cout << "Exiting...";

		}
		else if(sort == "-quick3")
		{
			std::cout << "Calculating sort timing information... \n";
			double timeQuickMedian = Sorts<int>::sortTimer(Sorts<int>::quickSortMedian, numArray, fileCount);
			myOutputFile << "Quick Sort with Median sort " <<  fileCount << " numbers in " << timeQuickMedian << " seconds\n";
			std::cout << "Calculations finshed. Results stored. \n";
			std::cout << "Exiting...";

		}
		else if(sort == "-merge")
		{
			std::cout << "Calculating sort timing information... \n";
			double timeMerge = Sorts<int>::sortTimer(Sorts<int>::mergeSort, numArray, fileCount);
			myOutputFile << "Merge Sort sort " <<  fileCount << " numbers in " << timeMerge << " seconds\n";
			std::cout << "Calculations finshed. Results stored. \n";
			std::cout << "Exiting...";

		}

		else if(sort == "-all")
		{
			std::cout << "Calculating sort timing information... \n";
			int* CopyArray = new int[fileCount];
			copyArray(numArray, CopyArray, fileCount);
			double timeBubble = Sorts<int>::sortTimer(Sorts<int>::bubbleSort, numArray, fileCount);

			copyArray(numArray, CopyArray, fileCount);
			double timeSelection = Sorts<int>::sortTimer(Sorts<int>::selectionSort, numArray, fileCount);

			copyArray(numArray, CopyArray, fileCount);
			double timeInsertion = Sorts<int>::sortTimer(Sorts<int>::insertionSort, numArray, fileCount);

			copyArray(numArray, CopyArray, fileCount);
			double timeQuick = Sorts<int>::sortTimer(Sorts<int>::quickSort, numArray, fileCount);

			copyArray(numArray, CopyArray, fileCount);
			double timeQuickMedian = Sorts<int>::sortTimer(Sorts<int>::quickSortMedian, numArray, fileCount);

			copyArray(numArray, CopyArray, fileCount);
			double timeMerge = Sorts<int>::sortTimer(Sorts<int>::mergeSort, numArray, fileCount);

			delete (CopyArray);
		
			myOutputFile << "Bubble Sort sort " <<  fileCount << " numbers in " << timeBubble << " seconds\n";
			myOutputFile << "Selection Sort sort " <<  fileCount << " numbers in " << timeSelection << " seconds\n";
			myOutputFile << "Insertion Sort sort " <<  fileCount << " numbers in " << timeInsertion << " seconds\n";
			myOutputFile << "Quick Sort sort " <<  fileCount << " numbers in " << timeQuick << " seconds\n";
			myOutputFile << "Quick Sort with Median sort " <<  fileCount << " numbers in " << timeQuickMedian << " seconds\n";
			myOutputFile << "Merge Sort sort " <<  fileCount << " numbers in " << timeMerge << " seconds\n";
			std::cout << "Calculations finshed. Results stored. \n";
			std::cout << "Exiting...";

		}

		delete (numArray);
	}

}

void SortDriver::printHelpMenu()
{
	std::cout << "\nSorting is done one of the following ways:\n\n"
			<< "./prog -sort -bubble inputFile outputFile\n"
			<< "./prog -sort -selection inputFile outputFile\n"
			<< "./prog -sort -insertion inputFile outputFile\n"
			<< "./prog -sort -quick inputFile outputFile\n"
			<< "./prog -sort -quick3 inputFile outputFile\n"
			<< "./prog -sort -merge inputFile outputFile\n"
			<< "./prog -sort -all inputFile outputFile\n"
			<< "Option explainations:\n"
			<< "\t-bubble to time bubble sort and store all timing results in outputFile\n"
			<< "\t-selection to time selection sort and store all timing results in outputFile\n"
			<< "\t-insertion to time insertion sort and store all timing results in outputFile\n"
			<< "\t-quick to time quick sort and store all timing results in outputFile\n"
			<< "\t-quick3 to time quick3 sort  and store all timing results in outputFile\n"
			<< "\t-merge to time merge sort  and store all timing results in outputFile\n"
			<< "\t-all to time all of the sorts and store all timing results in outputFile\n"
			<< "\tinputFile must be file created by a NumberFileGenerator\n"
			<< "\toutputFile must be to a valid path. It will hold the timing results\n";
}

bool SortDriver::isFileAccessible(std::string fileName)
{
	return true;
}

bool SortDriver::isSortValid(std::string sortParameter)
{
	if(sortParameter == "-bubble" || sortParameter == "-selection" || sortParameter == "-insertion" || sortParameter == "-quick" || sortParameter == "-quick3" || sortParameter == "-merge" || sortParameter == "-all" )
	{
		return true;
	}
	else
		return false;
}

bool SortDriver::areParametersValid(std::string sortName, std::string inputFileName)
{
	if(isFileAccessible(inputFileName) && isSortValid(sortName))
		return true;
	else
		return false;
}

int SortDriver::getFileCount(std::ifstream& inputFile)
{
	int count;
	if(inputFile.good())
	{
		inputFile >> count;
	}
	return count;
}

int* SortDriver::createArray(std::ifstream& inputFile, int size)
{
	int* arrPtr = new int[size];
	if(size == getFileCount(inputFile))
	{
		for (int i=0; i<size;i++)
		{
			inputFile >> arrPtr[i];
		}
	}
	return arrPtr;
}

void SortDriver::copyArray(int original[], int copy[], int size)
{
		
	for (int i=0; i<size; i++)
	{
		copy[i] = original[i];
	}
}	

