/**
*	@file : PreconditionViolationException.h
*	@author : Vuong Nguyen
*	@date : 2015.03.05
*	Purpose: Header file of PreconditionViolationException class
*/

#ifndef PRECONDITIONVIOLATIONEXCEPTION_H
#define PRECONDITIONVIOLATIONEXCEPTION_H
#include <stdexcept>

class PreconditionViolationException : public std::runtime_error
{
public:
	/**
	*  @pre None
	*  @post Calls the constructor of std::runtime_error, passing it the message
	*  @return A std::runtime_error object with the message passed into it
	*/
    PreconditionViolationException(const char* message);
};

#endif // PRECONDITIONVIOLATIONEXCEPTION_H
