/**
*	@file : AnimalPen.h
*	@author :  Vuong Nguyen
*	@date : 2015.03.16
*	Purpose: Header file of AnimaPen Class. 
*/

#ifndef ANIMALPEN_H
#define ANIMALPEN_H

#include "Stack.h"
#include "FarmAnimal.h"


class AnimalPen: public Stack<FarmAnimal*>
{
	public: 
	
	/**
	*  @pre None
	*  @post Creates a animal pen
	*  @return A stack of animal
	*/
	AnimalPen();

	/**
	*  @pre None
	*  @post Deletes all animals in the pen
	*  @return None
	*/
	~AnimalPen();

	/**
	*  @pre None
	*  @post Pushes the animal pointer into the pen (onto the stack)
	*  @return None
	*/
    	void addAnimal(FarmAnimal* animal);

	/**
	*  @pre None
	*  @post None
	*  @return A pointer to the next animal, but does not remove it
	*/
    	FarmAnimal* peakAtNextAnimal();

	/**
	*  @pre None
	*  @post Deletes animal and removes from stack
	*  @return None
	*/
    	void releaseAnimal();

	/**
	*  @pre None
	*  @post Indicates if the pen is empty
	*  @return true if the pen is empty, false otherwise
	*/
    	bool isPenEmpty();
};
#endif
