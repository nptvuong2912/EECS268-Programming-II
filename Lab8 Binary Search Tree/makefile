Lab08: main.o ValueNotFoundException.o
	g++ -g -std=c++11 main.o ValueNotFoundException.o -o Lab08

main.o: main.cpp BinarySearchTree.h BinarySearchTree.hpp ValueNotFoundException.cpp ValueNotFoundException.h Node.h Node.hpp
	g++ -g -std=c++11 -c main.cpp

ValueNotFoundException.o: ValueNotFoundException.cpp ValueNotFoundException.h 
	g++ -g -std=c++11 -c ValueNotFoundException.cpp
clean:
	rm *.o *~ Lab08
