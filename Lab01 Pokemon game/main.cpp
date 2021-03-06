
/**
*	@file : main.cpp
*	@author :  Vuong Nguyen
*	@date : 2015.02.05
*	Purpose: The main class to utilize other classes to declare Pokemons and use Colosseum class methods 
	to build the Pokemons as well as control the program
*/


#include<iostream>
#include<string>
#include "Pokemon.h"
#include "Colosseum.h"

int main()
{
	Pokemon p1;
	Pokemon p2;
	Colosseum c;
	
	char again = 'y';
	while (again == 'y') //Repeats asking the user to play again
	{
		std::cout<< "\n" << "Player 1, build your Pokemon!" << "\n";
		std::cout<<"============================" << "\n";
		c.userBuild(p1); //Builds Pokemon 1
		std::cout<<"Player 2, build your Pokemon!" << "\n";
		std::cout<<"============================" << "\n";
		c.userBuild(p2); //Builds Pokemon 2

		c.play(p1, p2); //calls play from Colosseum class
		std::cout<< "\n" << "Do you want to play again? (y/n): ";
		std::cin >> again;
		std::cout<< "\n";
	}
	

	return 0;
}


