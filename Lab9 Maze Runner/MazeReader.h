
/**
*	@file : MazeReader.h
*	@author :  Vuong Nguyen
*	@date : 2015.04.17
*	Purpose: Header file of MazeReader Class. 
**/


#ifndef MAZEREADER_H
#define MAZEREADER_H
#include <iostream>
#include <fstream>
#include <string>

#include "MazeCreationException.h"

class MazeReader
{
  public:
  /**
  *  @pre none
  *  @post creates a MazeReader and read the 2D char array into the maze, throws exception otherwise.
  *  @return none
  */ 
  MazeReader(std::string file) throw (MazeCreationException); 
  /**
  *  @pre none
  *  @post the maze is deallocated
  *  @return none
  */ 
  ~MazeReader();
  
  /**
  *  @pre the file is formatting and read in correctly
  *  @post  none
  *  @return the pointer to the maze
  */ 
  char** getMaze() const;
  
  /**
  *  @pre the file is formatting and read in correctly
  *  @post  none
  *  @return number of columns listed in the file
  */ 
  int getCols() const;
  
   /**
  *  @pre the file is formatting and read in correctly
  *  @post  none
  *  @return number of rows listed in the file
  */ 
  int getRows() const;
  
   /**
  *  @pre the file is formatting and read in correctly
  *  @post  none
  *  @return the starting column
  */ 
  int getStartCol() const;
  
   /**
  *  @pre the file is formatting and read in correctly
  *  @post  none
  *  @return the starting row
  */ 
  int getStartRow() const;
  
  
protected:
  /**
   *  @pre the file is properly formatted
   * 	@post the characters representing the maze are stored
   * 	@return none
   */
  void readMaze() throw (MazeCreationException);

private:
	int m_rows;
	int m_cols;
	char** m_maze;
	int m_startCol;
	int m_startRow;
	std::ifstream fin;
  
};
#endif
