/**
*	@file : ValueNotFoundException.cpp
*	@author : Vuong Nguyen
*	@date : 2015.04.14
*	Purpose: Implementation of ValueNotFoundException class
*/

#include "ValueNotFoundException.h"

ValueNotFoundException::ValueNotFoundException(const char *message) : std::runtime_error(message)
{

}
