/**
*	@file : CyberChicken.h
*	@author :  Vuong Nguyen
*	@date : 2015.03.16
*	Purpose: Header file of CyberChicken Class. 
*/

#ifndef CYBERCHICKEN_H
#define CYBERCHICKEN_H

#include "Chicken.h"

class CyberChicken: public Chicken
{
	public:
	/**
	*  @pre None
	*  @post Creates and initializes a Cyber Chicken instance
	*  @return Initialzed Cyber chicken
	*/
	CyberChicken();

	/**
	*  @pre None
	*  @post None
	*  @return the value of the inherited member variable m_eggs
	*/
	int getCyberEggs() const;

	/**
	*  @pre None
	*  @post set the value of m_eggs
	*  @return none
	*/
	void setCyberEggs(int eggs);
};
#endif
