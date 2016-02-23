/**
*	@file : MazeCreationException.h
*	@author : Vuong Nguyen
*	@date : 2015.04.17
*	Purpose: Header file of MazeCreationException class
*/

#ifndef MAZECREATIONEXCEPTION_H
#define MAZECREATIONEXCEPTION_H
#include <stdexcept>

class MazeCreationException : public std::runtime_error
{
public:
	/**
	*  @pre None
	*  @post Calls the constructor of std::runtime_error, passing it the message
	*  @return A std::runtime_error object with the message passed into it
	*/
    MazeCreationException(const char* message);
};

#endif 
