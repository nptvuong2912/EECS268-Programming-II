/**
*	@file : Chicken.cpp
*	@author :  Vuong Nguyen
*	@date : 2015.03.16
*	Purpose: Implementation file of Chicken Class. 
*/

#include "Chicken.h"

Chicken::Chicken()
{
	m_name = "Chicken";
	m_sound = "Cluck";
}

int Chicken::getEggs() const
{
	return m_eggs;
}

void Chicken::setEggs(int eggs)
{
	m_eggs = eggs;
}
