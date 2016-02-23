/**
*	@file : Cow.cpp
*	@author :  Vuong Nguyen
*	@date : 2015.03.16
*	Purpose: Implementation file of Cow Class. 
*/

#include "Cow.h"

Cow::Cow()
{
	m_name = "Cow";
	m_sound = "Moo";
}
	
double Cow::getMilkProduced() const
{
	return m_milkProduced;
}

void Cow::setMilkProduced(double gallons)
{
	if (gallons >0 )
	{
		m_milkProduced = gallons;
	}
	else
	{
		m_milkProduced = 0;
	}
}
