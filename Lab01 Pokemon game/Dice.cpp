
/**
*	@file : Dice.cpp
*	@author :  Vuong Nguyen
*	@date : 2015.02.05
*	Purpose: Implementation of Dice Class
*/



#include "Dice.h"

Dice::Dice()//return Initialzed Dice with 6 sides
{
	m_numSides = 6; //initialize random seed:
	srand (time(NULL));
}

Dice::Dice(int numSides)
{
	m_numSides = numSides; //initialize random seed:
	srand (time(NULL));
}

int Dice::roll()
{
	return(rand()%m_numSides + 1); //return a pseudo-random number
}
