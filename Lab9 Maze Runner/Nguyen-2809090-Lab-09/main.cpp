/**
*	@file : main.cpp
*	@author :  Vuong Nguyen
*	@date : 2015.04.19
*	Purpose: Implementation file of main function
*/

#include "MazeWalker.h"
#include "MazeReader.h"
#include "Position.h"
#include "MazeCreationException.h"
#include <string>
#include <iostream>
#include <stdexcept>

int main(int argc, char** argv)
{

	if(argc != 3)
	{
		std::cout << "Lack of command line arguments.\n";
	}
	else if(argc == 3)
	{
		if((std::string)argv[2] != "-dfs" && (std::string)argv[2] != "-bfs")
		{
			std::cout << "The search options must be either -dfs or -bfs.\n";
		}
		else
		{
		
			std::string file = (std::string)argv[1];

			MazeReader* reader = new MazeReader(file);
			
			int rows = reader->getRows();
			int cols = reader->getCols();
			int startRow = reader->getStartRow();		
			int startCol = reader->getStartCol();
			char** maze = reader->getMaze();


			if((std::string)argv[2] == "-dfs")
			{
				MazeWalker* walker = new MazeWalker(maze, startRow, startCol, rows, cols, true);
				walker->walkMaze();
				delete(walker);
			}
			else if((std::string)argv[2] == "-bfs")
			{
				MazeWalker* walker = new MazeWalker(maze, startRow, startCol, rows, cols, false);
				walker->walkMaze();
				delete(walker);
			}

			delete(reader);
			
		}	
	}

	
	return 0;
}
