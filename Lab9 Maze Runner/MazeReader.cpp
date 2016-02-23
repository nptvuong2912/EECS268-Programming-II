/**
*	@file : MazeReader.cpp
*	@author :  Vuong Nguyen
*	@date : 2015.04.17
*	Purpose: Implementation file of MazeReader Class. 
**/

#include "MazeReader.h"
#include <string>
#include <fstream>

MazeReader::MazeReader(std::string file) throw (MazeCreationException)
{
	
	fin.open(file);

	

	if(!fin.is_open())
	{
		throw(MazeCreationException("The file cannot be opened!"));
	}
	else
	{
		fin >> m_rows;
		fin >> m_cols;
	
		fin >> m_startRow;
		fin >> m_startCol;

		if (m_rows <= 0 || m_cols <= 0)
		{
			throw(MazeCreationException("The numbers of rows or columns are less than or equal to zero."));
		}
		else if (m_startCol > m_cols || m_startRow > m_rows || m_startCol < 0 || m_startRow < 0)
		{
			throw(MazeCreationException("The start position is outside the range of the maze."));
		}
		else
		{
			m_maze = new char*[m_rows];

			for (int i = 0; i< m_rows; i++)
			{
				m_maze[i] = new char[m_cols];
			}
			
			readMaze();
		}
	}

	fin.close();	
}

MazeReader::~MazeReader()
{
	for(int i=0; i< m_rows; i++)
	{		
		delete[] m_maze[i];
	}
	delete[] m_maze;

}

char** MazeReader::getMaze() const
{			
	return m_maze;
}

int MazeReader::getCols() const
{
	return m_cols;
}	
int MazeReader::getRows() const
{
	return m_rows;
}

int MazeReader::getStartCol() const
{
	return m_startCol;
}
int MazeReader::getStartRow() const
{
	return m_startRow;
}

void MazeReader::readMaze() throw (MazeCreationException)
{
	for (int i=0; i< m_rows; i++)
	{
		for(int j=0; j< m_cols; j++)
		{
			fin >> m_maze[i][j];
		}
	}

}










