/**
*	@file : Node.h
*	@author :  Vuong Nguyen
*	@date : 2015.03.02
*	Purpose: Header file of Node Class. 
*/


#ifndef NODE_H
#define NODE_H
#include <iostream>

template <typename T>
class Node
{
	private:
	T m_value;
	Node<T>* m_next;

	public:

	/**
	*  @pre none
	*  @post Constructor to create the nodes
	*  @return none
	*/
	Node();

	/**
	*  @pre None
	*  @post set the value of the node
	*  @return none
	*/
	void setValue(T value);

	/**
	*  @pre None
	*  @post set the m_next pointer
	*  @return none
	*/
	void setNext(Node<T>* prev);


	/**
	*  @pre None
	*  @post None
	*  @return the value of m_value
	*/
	T getValue();

	/**
	*  @pre None
	*  @post None
	*  @return the value of m_next
	*/
	Node<T>* getNext();

};

#include "Node.hpp"
#endif
