/**
*	@file : Cow.h
*	@author :  Vuong Nguyen
*	@date : 2015.03.16
*	Purpose: Header file of Cow Class. 
*/

#ifndef COW_H
#define COW_H

#include "FarmAnimal.h"

class Cow: public FarmAnimal
{
	protected:
	double m_milkProduced;

	public:

	/**
	*  @pre None
	*  @post Creates and initializes a Cow instance
	*  @return Initialzed cow
	*/
	Cow();

	/**
	*  @pre None
	*  @post None
	*  @return the value of milk produced
	*/
	double getMilkProduced() const;

	/**
	*  @pre None
	*  @post set the value of milk produced
	*  @return none
	*/
	void setMilkProduced(double gallons);
};
#endif
