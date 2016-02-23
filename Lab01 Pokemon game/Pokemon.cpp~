
/**
*	@file : Pokemon.cpp
*	@author :  Vuong Nguyen
*	@date : 2015.02.05
*	Purpose: Implementation of Pokemon class
*/


#include "Pokemon.h"

Pokemon::Pokemon()
{
	m_hp = 0;
	
	m_name = "";
} 

//set methods for Hp, attackLevel, defenseLevel and name
void Pokemon::setHp(int hp)
{
	m_hp = hp;
}
void Pokemon::setAttack(int attackLevel)
{
	m_attackLevel = attackLevel;
}
void Pokemon::setDefense(int defenseLevel)
{
	m_defenseLevel = defenseLevel;
}
void Pokemon::setName(std::string name)
{
	m_name = name;
}

//get methods are all const
int Pokemon::getHp() const
{
	return(m_hp);
}
int Pokemon::getAttack() const
{
	return(m_attackLevel);
}
int Pokemon::getDefense() const
{
	return(m_defenseLevel);
}
std::string Pokemon::getName() const
{
	return(m_name);
}

void Pokemon::reduceHp(int amount)
{
	m_hp = m_hp - amount;
} //reduces m_hp and doesn't prevent m_hp becoming a negative value
	
