Lab07: main.o SortDriver.o NumberFileGenerator.o NumberFileDriver.o
	g++ -g -std=c++11 -Wall main.o SortDriver.o NumberFileGenerator.o NumberFileDriver.o -o Lab07

main.o: main.cpp Sorts.h Sorts.hpp SortDriver.h NumberFileGenerator.h NumberFileDriver.h
	g++ -g -std=c++11 -Wall -c main.cpp

SortDriver.o: SortDriver.cpp SortDriver.h 
	g++ -g -std=c++11 -c SortDriver.cpp

NumberFileGenerator.o: NumberFileGenerator.cpp NumberFileGenerator.h 
	g++ -g -std=c++11 -c NumberFileGenerator.cpp

NumberFileDriver.o: NumberFileDriver.cpp NumberFileDriver.h 
	g++ -g -std=c++11 -c NumberFileDriver.cpp

clean:
	rm *.o *~ Lab07
