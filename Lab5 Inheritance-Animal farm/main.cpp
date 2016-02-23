/**
*	@file : main.cpp
*	@author : Vuong Nguyen
*	@date : 2015.03.18
*	Purpose: Implementation of main function
*/
#include "AnimalPen.h"
#include "Chicken.h"
#include "Cow.h"
#include "CyberChicken.h"
#include <iostream>

void goodbyeMessage(const FarmAnimal& animal)
{
    std::cout << "Upon release the " << animal.getName() << " said " << animal.getSound() << '\n';
}

int main()
{
	AnimalPen pen;
	FarmAnimal* AnimalPtr = nullptr;
	Cow* CowPtr = nullptr;
	Chicken* ChickenPtr = nullptr;
	CyberChicken* CyberChickenPtr = nullptr;
    	char done = 'n';
    	while (done == 'n')
    	{
        	int choice;
        	std::cout << "Select an animal to add to the pen" << '\n';
        	std::cout << "1.) Cow (produces milk)" << '\n';
        	std::cout << "2.) Chicken (cannot lay eggs)" << '\n';
        	std::cout << "3.) CyberChicken (seems dangerous, but lay eggs)" << '\n';
        	std::cout << "---------------------------------------------------" << '\n';
        	std::cin >> choice;
        	std::cout << "choice: ";
		if (choice == 1)
		{
			CowPtr = new Cow();
			double gallons;
			std::cout << "How many gallons of milk did this cow produce?: ";
			std::cin >> gallons;
			CowPtr->setMilkProduced(gallons);
			pen.addAnimal(CowPtr);
		}
		else if (choice == 2)
		{
			ChickenPtr = new Chicken();
			std::cout << "Add an eggless chicken to the pen? OK. You're the boss." << '\n';
			pen.addAnimal(ChickenPtr);
		}
		else if (choice == 3)
		{
			CyberChickenPtr = new CyberChicken();
			int eggs;
			std::cout << "How many eggs did this cyber chicken produce?: ";
			std::cin >> eggs;
			CyberChickenPtr->setCyberEggs(eggs);
			pen.addAnimal(CyberChickenPtr);
		}
        	std::cout << "Done adding animals? (y/n)";
        	std::cin >> done;
        	std::cout << '\n' << '\n';
    	}

	std::cout << "Releasing all animals!" << '\n';
    	std::cout << "-------------------------" << '\n';

	double total_milk = 0;
	int total_eggs = 0;

	while (!(pen.isPenEmpty()))
	{
		AnimalPtr = pen.peakAtNextAnimal();

		if (AnimalPtr->getName() == "Cyber Chicken")
		{
			CyberChickenPtr = static_cast<CyberChicken*>(AnimalPtr);
			std::cout << "This Cyber Chicken laid " << CyberChickenPtr->getCyberEggs() << " cyber eggs. Humanity is in trouble." << '\n';
			total_eggs += CyberChickenPtr->getCyberEggs();
			goodbyeMessage(*AnimalPtr);
			std::cout << "CyberChicken Destructor called" << '\n';
			std::cout << "Chicken Destructor called" << '\n';
		}

		if (AnimalPtr->getName() == "Chicken")
		{
			ChickenPtr = static_cast<Chicken*>(AnimalPtr);
			std::cout << "Chicken unable to lay eggs. Perhaps cybornetic implants will help?" << '\n';
			goodbyeMessage(*AnimalPtr);
			std::cout << "Chicken Destructor called" << '\n';
		}

		if (AnimalPtr->getName() == "Cow")
		{
			CowPtr = static_cast<Cow*>(AnimalPtr);
			std::cout << "This cow produced " << CowPtr->getMilkProduced() << " gallons of milk" << '\n';
			total_milk += CowPtr->getMilkProduced();
			goodbyeMessage(*AnimalPtr);
		}
		delete AnimalPtr;
		pen.releaseAnimal();
	}

	std::cout << "Your farm produced " << total_milk << " gallons of milk and " << total_eggs << " eggs.";
	return 0;
}






