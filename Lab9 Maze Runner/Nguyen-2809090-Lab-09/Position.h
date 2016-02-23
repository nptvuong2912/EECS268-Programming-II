/**
*	@file : Position.h
*	@author :  Vuong Nguyen
*	@date : 2015.04.17
*	Purpose: Header file of Position Class. 
**/

#ifndef POSITION_H
#define POSITION_H
#include <iostream>

class Position
{
  
  private:
   int m_row;
   int m_col;
   
  public:
  /**
*  @pre none
*  @post Creates Position with row and column set
*  @return none
*/
    Position(int row, int col);
  
/**
*  @pre none
*  @post none
*  @return row value
*/  
    int getRow() const;
  
/**
*  @pre none
*  @post none
*  @return column value
*/    
    int getCol() const;
  
};

#endif
