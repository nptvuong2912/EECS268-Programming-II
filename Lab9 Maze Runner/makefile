Lab09: main.o Position.o MazeReader.o MazeWalker.o MazeCreationException.o
	g++ -g -std=c++11 main.o Position.o MazeReader.o MazeWalker.o MazeCreationException.o -o Lab09

main.o: main.cpp Position.h MazeReader.h MazeWalker.h MazeCreationException.h 
	g++ -g -std=c++11 -c main.cpp

Position.o: Position.h Position.cpp
	g++ -g -std=c++11 -c Position.cpp

MazeReader.o: MazeReader.h MazeReader.cpp
	g++ -g -std=c++11 -c MazeReader.cpp

MazeWalker.o: MazeWalker.h MazeWalker.cpp
	g++ -g -std=c++11 -c MazeWalker.cpp

MazeCreationException.o: MazeCreationException.cpp MazeCreationException.h 
	g++ -g -std=c++11 -c MazeCreationException.cpp
clean:
	rm *.o *~ Lab09
