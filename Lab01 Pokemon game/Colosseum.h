
/**
*	@file : Colosseum.h
*	@author :  Vuong Nguyen
*	@date : 2015.02.05
*	Purpose: Header file of Colosseum Class. Used to create public methods to build the pokemons, attack and control the play
*/


#ifndef COLOSSEUM_H
#define COLOSSEUM_H


#include <string>
#include "Dice.h"
#include "Pokemon.h"

class Colosseum
{
	private:  
	Dice d20;
	Dice d6;
	Dice d2;

	public:
	Colosseum(); //Initializes Dice to appropriate sizes
	void userBuild(Pokemon& p); //Sets info for the pokemon with name, hp (1-50), attack+defense = (1-50)

	bool attack(const Pokemon& attacker, Pokemon& defender); 
	/*
		- Calculate attack and defense bonuses by roll d20 randomly
		- The attack hits if attackLevel+ attackBonus > defenseLevel+ defenseBonus
		- Damage equals to three random rolls of d6 (if the attack hits)
		- Display info about the attack
		- Returns true only if the opponent died after the attack, otherwise returns false		
	*/
	
	void play(Pokemon& p1, Pokemon& p2);	
	/*
		- Handles the 10th round, roll d2 to decide who goes first.
		- Display round info and calls attack() to display attack info
		- Determines when the game is over.
	*/	

	







};

#endif
