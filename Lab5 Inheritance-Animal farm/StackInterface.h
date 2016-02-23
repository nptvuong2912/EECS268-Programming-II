/**
*	@file : StackInterface.h
*	@author :  Vuong Nguyen
*	@date : 2015.03.04
*	Purpose: Interface of Stack Class. 
*/

#ifndef STACKINTERFACE_H
#define STACKINTERFACE_H
#include "Node.h"
#include "PreconditionViolationException.h"
#include <iostream>
#include <stdexcept>
#include <string>


template <typename T>
class StackInterface
{
	private:
	Node<T>* m_front;
	int m_size;

	public:
	/**
	*  @pre None
	*  @post Method to deletes all the nodes
	*  @return deleted Stack
	*/
	virtual ~StackInterface() {};
	/**
	*  @pre none
	*  @post none
	*  @return true only if the list is empty
	*/
	virtual bool isEmpty() const = 0;

	/**
	*  @pre none
	*  @post add the new value to the top of the stack
	*  @return none
	*/
	virtual void push(const T newEntry) = 0;
	/**
	*  @pre none
	*  @post none
	*  @return the number of nodes in the list
	*/
	virtual int size() const = 0;
	/**
	*  @pre assumes the stack is not empty
	*  @post removes the top of the stack or throws PVE when a pop is attempted on an empty stack
	*  @return the value of the entry at the top
	*/
	virtual T pop() throw(PreconditionViolationException) = 0;
	/**
	*  @pre assumes the stack is not empty
	*  @post throws PVE if a peek is attempted on an empty stack
	*  @return the value of the entry at the top
	*/
	virtual T peek() const throw(PreconditionViolationException) = 0;
	
	/**
	*  @pre none
	*  @post Print the stack and "Stack empty" if there is no element.
	*  @return none
	*/
	virtual void print() const = 0;
	/**
	*  @pre none
	*  @post none
	*  @return true if the stack's size is less than the rhs's size
	*/
	virtual bool operator< (const StackInterface<T>& rhs) const = 0;
	/**
	*  @pre none
	*  @post none
	*  @return true if the stack's size is less than or equal to the rhs's size
	*/
	virtual bool operator<= (const StackInterface<T>& rhs) const = 0;
	/**
	*  @pre none
	*  @post none
	*  @return true if the stack's size is greater than the rhs's size
	*/
	virtual bool operator> (const StackInterface<T>& rhs) const = 0;
	/**
	*  @pre none
	*  @post none
	*  @return true if the stack's size is greater than or equal to the rhs's size
	*/
	virtual bool operator>= (const StackInterface<T>& rhs) const = 0;
	/**
	*  @pre none
	*  @post none
	*  @return true if the stack's size is equal to the rhs's size
	*/
	virtual bool operator== (const StackInterface<T>& rhs) const = 0;
	/**
	*  @pre none
	*  @post none
	*  @return true if the stack's size is not equal to the rhs's size
	*/
	virtual bool operator!= (const StackInterface<T>& rhs) const = 0;
};
#endif
