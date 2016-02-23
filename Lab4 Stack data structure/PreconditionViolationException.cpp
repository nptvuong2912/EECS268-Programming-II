/**
*	@file : PreconditionViolationException.cpp
*	@author : Vuong Nguyen
*	@date : 2015.03.05
*	Purpose: Implementation of PreconditionViolationException class
*/

#include "PreconditionViolationException.h"

PreconditionViolationException::PreconditionViolationException(const char *message) : std::runtime_error(message)
{
}
