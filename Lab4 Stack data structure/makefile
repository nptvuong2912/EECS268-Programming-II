Lab04: main.o PreconditionViolationException.o
	g++ -g -std=c++11 main.o PreconditionViolationException.o -o Lab04

main.o: main.cpp Stack.h Stack.hpp PreconditionViolationException.cpp PreconditionViolationException.h Node.h Node.hpp
	g++ -g -std=c++11 -c main.cpp

PreconditionViolationException.o: PreconditionViolationException.cpp PreconditionViolationException.h 
	g++ -g -std=c++11 -c PreconditionViolationException.cpp