/**
*	@file : MazeWalker.h
*	@author :  Vuong Nguyen
*	@date : 2015.04.19
*	Purpose: Header file of MazeWalker Class. 
**/


#ifndef MAZEWALKER_H
#define MAZEWALKER_H
#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <queue>	

#include "Position.h"

class MazeWalker
{

	public:
	/**
  	*  @pre The mazePtr points to a valid maze
  	*  @post creates a MazeWalker with all needed flags set and visited array contains all false.
  	*  @return none
  	*/ 
	MazeWalker(char**mazePtr, int startRow, int startCol, int rows, int cols, bool dfs);

	/**
  	*  @pre none
  	*  @post delete the m_visited 
  	*  @return none
  	*/
	~MazeWalker();

	/**
  	*  @pre The maze is a valid maze
  	*  @post the maze is traversed until the end is reached or all moves are exhausted, prints visited array during.
  	*  @return none
  	*/ 
	void walkMaze();

	private:

	bool m_isDFS;
	char** m_maze;
	bool** m_visited;
	int m_rows, m_cols;
	Position m_curPos;
	Position m_startPos;

	std::stack<Position> m_moveStack;
	std::queue<Position> m_moveQueue;

	protected:
	/**
  	*  @pre current position is valid
  	*  @post either stack or queue is loaded with possible moves from current position.
  	*  @return none
  	*/ 
	void storeValidMoves();

	/**
  	*  @pre position is valid
  	*  @post the current position is set up to p and theposition is updated as mark.
  	*  @return none
  	*/ 
	void move(Position& p);

	/**
  	*  @pre none
  	*  @post none
  	*  @return true the end is reached as current position.
  	*/
	bool isGoalReached() const;

};
#endif


	
	
	
	

	
