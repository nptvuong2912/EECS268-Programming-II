/**
*	@file : Pokemon.h
*	@author :  Vuong Nguyen
*	@date : 2015.02.05
*	Purpose: Header file of Pokemon Class. Used to create the pokemons with name, health points, attack Level and defense Level.
*/


#ifndef POKEMON_H
#define POKEMON_H

#include <string>

class Pokemon
{
	private:
	int m_hp;
	int m_attackLevel;
	int m_defenseLevel;
	std::string m_name;

	public:
	Pokemon(); //Initializes all numeric date to zero and strings to ""
	
	void reduceHp(int amount); //reduce m_hp and doesn't prevent m_hp becoming a negative value
	
	//Get methods
	int getHp() const;
	int getAttack() const;
	int getDefense() const;
	std::string getName() const;

	//Set methods
	void setHp(int hp);
	void setAttack(int attackLevel);
	void setDefense(int defenseLevel);
	void setName(std::string m_name);
};

#endif
