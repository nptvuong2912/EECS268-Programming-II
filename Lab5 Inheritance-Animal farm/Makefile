Lab05: main.o AnimalPen.o Chicken.o Cow.o CyberChicken.o FarmAnimal.o PreconditionViolationException.o
	g++ -g -std=c++11 main.o AnimalPen.o Chicken.o Cow.o CyberChicken.o FarmAnimal.o PreconditionViolationException.o -o Lab05

main.o: main.cpp FarmAnimal.h Chicken.h Cow.h CyberChicken.h PreconditionViolationException.h
	g++ -g -std=c++11 -c main.cpp

AnimalPen.o: AnimalPen.cpp AnimalPen.h 
	g++ -g -std=c++11 -c AnimalPen.cpp

Chicken.o: Chicken.cpp Chicken.h
	g++ -g -std=c++11 -c Chicken.cpp

Cow.o: Cow.cpp Cow.h
	g++ -g -std=c++11 -c Cow.cpp

CyberChicken.o: CyberChicken.cpp CyberChicken.h
	g++ -g -std=c++11 -c CyberChicken.cpp

FarmAnimal.o: FarmAnimal.cpp FarmAnimal.h
	g++ -g -std=c++11 -c FarmAnimal.cpp

PreconditionViolationException.o: PreconditionViolationException.cpp PreconditionViolationException.h 
	g++ -g -std=c++11 -c PreconditionViolationException.cpp
