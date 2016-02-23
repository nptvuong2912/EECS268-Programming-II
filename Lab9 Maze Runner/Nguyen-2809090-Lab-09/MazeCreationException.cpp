/**
*	@file : MazeCreationException.cpp
*	@author : Vuong Nguyen
*	@date : 2015.04.17
*	Purpose: Implementation of MazeCreationException class
*/

#include "MazeCreationException.h"

MazeCreationException::MazeCreationException(const char *message) : std::runtime_error(message)
{

}
