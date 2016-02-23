
/**
*	@file : Dice.h
*	@author :  Vuong Nguyen
*	@date : 2015.02.05
*	Purpose: Header file of Dice Class. Used to emulate a dice with the number of sides given at construction time.
*/

#ifndef DICE_H
#define DICE_H

#include <cstdio>
#include <cstdlib>
#include <ctime>

class Dice
{
	public:
	Dice(); //return Initialzed Dice with 6 sides

	Dice(int numSides); //return Initialzed Dice with m_numSides initialzed to numSides.
	

	int roll(); //return a pseudo-random num from 1+ and including and m+numSides

	int getNumSides(); //return the value of m_numSides

	private:
	int m_numSides;
};

#endif
