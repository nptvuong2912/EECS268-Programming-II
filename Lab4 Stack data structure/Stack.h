/**
*	@file : Stack.h
*	@author :  Vuong Nguyen
*	@date : 2015.03.02
*	Purpose: Header file of Stack Class. 
*/

#ifndef STACK_H
#define STACK_H
#include "Node.h"
#include "StackInterface.h"
#include <iostream>
#include <stdexcept>

template <typename T>
class Stack: public StackInterface<T>
{	
	private:
	Node<T>* m_front;
	int m_size;

	public:
	/**
	*  @pre None
	*  @post Creates and initializes a Stack instance
	*  @return Initialzed Stack
	*/
	Stack();
	
	/**
	*  @pre None
	*  @post Method to deletes all the nodes
	*  @return deleted Stack
	*/
	~Stack();
	
	/**
	*  @pre none
	*  @post none
	*  @return true only if the list is empty
	*/
	bool isEmpty() const;
	
	/**
	*  @pre none
	*  @post none
	*  @return the number of nodes in the list
	*/
	int size() const;

	/**
	*  @pre none
	*  @post add the new value to the top of the stack
	*  @return none
	*/
	void push(const T newEntry);
	
	/**
	*  @pre assumes the stack is not empty
	*  @post removes the top of the stack or throws PVE when a pop is attempted on an empty stack
	*  @return the value of the entry at the top
	*/
	T pop() throw(PreconditionViolationException);
	
	/**
	*  @pre assumes the stack is not empty
	*  @post throws PVE if a peek is attempted on an empty stack
	*  @return the value of the entry at the top
	*/
	T peek() const throw(PreconditionViolationException);
	
	
	/**
	*  @pre none
	*  @post Print the stack and "Stack empty" if there is no element.
	*  @return none
	*/
	void print() const;

	/**
	*  @pre none
	*  @post none
	*  @return true if the stack's size is less than the rhs's size
	*/
	bool operator< (const StackInterface<T>& rhs) const;

	/**
	*  @pre none
	*  @post none
	*  @return true if the stack's size is less than or equal to the rhs's size
	*/
	bool operator<= (const StackInterface<T>& rhs) const;

	/**
	*  @pre none
	*  @post none
	*  @return true if the stack's size is greater than the rhs's size
	*/
	bool operator> (const StackInterface<T>& rhs) const;

	/**
	*  @pre none
	*  @post none
	*  @return true if the stack's size is greater than or equal the rhs's size
	*/
	bool operator>= (const StackInterface<T>& rhs) const;
	
	/**
	*  @pre none
	*  @post none
	*  @return true if the stack's size is equal the rhs's size
	*/
	bool operator== (const StackInterface<T>& rhs) const;
	
	/**
	*  @pre none
	*  @post none
	*  @return true if the stack's size is not equal the rhs's size
	*/
	bool operator!= (const StackInterface<T>& rhs) const;
	
};
#include "Stack.hpp"	
#endif
