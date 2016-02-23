/**
*	@file : Chicken.h
*	@author :  Vuong Nguyen
*	@date : 2015.03.16
*	Purpose: Header file of Chicken Class. 
*/

#ifndef CHICKEN_H
#define CHICKEN_H

#include "FarmAnimal.h"

class Chicken: public FarmAnimal
{
	protected:

	/**
	*  @pre None
	*  @post None
	*  @return the value of m_eggs
	*/
	int getEggs() const;

	/**
	*  @pre None
	*  @post Set the value of m_eggs
	*  @return None
	*/
	void setEggs(int eggs);

	int m_eggs;

	public:
	/**
	*  @pre None
	*  @post Creates and initializes a Chicken instance
	*  @return Initialzed chicken
	*/
	Chicken();
};
#endif
