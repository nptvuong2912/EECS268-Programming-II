/**
*	@file : Sorts.h
*	@author : Vuong Nguyen
*	@date : 2015.04.02
*	Purpose: Header file of Sorts class
*/

#include <random>
#include <ctime>
#ifndef SORTS_H
#define SORTS_H

template<typename T>
class Sorts
{
public:
	
	/**
	*  @pre arr is an array of valid Ts and the < operator is overloaded properly
	*  @post None
	*  @return None
	*/
    	static void bubbleSort(T arr[], int size);

	/**
	*  @pre None
	*  @post Sorts arr using bogo sort algorithm
	*  @return None
	*/
    	static void bogoSort(T arr[], int size);

	/**
	*  @pre None
	*  @post Sorts arr using insertion sort algorithm
	*  @return None
	*/
    	static void insertionSort(T arr[], int size);
    	
	/**
	*  @pre None
	*  @post Sorts arr using selection sort
	*  @return None
	*/
    	static void selectionSort(T arr[], int size);

	/**
	*  @pre None
	*  @post None
	*  @return true is arr is in ascending order, false otherwise
	*/
    	static bool isSorted(T arr[], int size);


private:
	/**
	*  @pre None
	*  @post For each index of the array, swap it the value at ampther random index
	*  @return None
	*/
    	static void shuffle(T arr[], int size, std::default_random_engine& generator);
};
#include "Sorts.hpp"

#endif // SORTS_H

