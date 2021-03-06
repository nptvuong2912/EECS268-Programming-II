
/**
*	@file : Node.h
*	@author :  Vuong Nguyen
*	@date : 2015.04.09
*	Purpose: Header file of Node Class. 
*/


#ifndef NODE_H
#define NODE_H
#include <iostream>

template <typename T>
class Node
{
	private:
	Node<T>* m_left;
	Node<T>* m_right;
	T m_value;

	public:
	/**
	*  @pre none
	*  @post Constructor to create the nodes
	*  @return none
	*/
	Node();


	Node(const Node<T>& other);

	/**
	*  @pre None
	*  @post None
	*  @return the value of m_value
	*/
	T getValue();

	/**
	*  @pre None
	*  @post None
	*  @return the value of m_left
	*/
	Node<T>* getLeft();

	/**
	*  @pre None
	*  @post None
	*  @return the value of m_right
	*/
	Node<T>* getRight();

	/**
	*  @pre None
	*  @post set the value of the node
	*  @return none
	*/
	void setValue(T value);

	/**
	*  @pre None
	*  @post set the m_left pointer
	*  @return none
	*/
	void setLeft(Node<T>* left);

	/**
	*  @pre None
	*  @post set the m_right pointer
	*  @return none
	*/
	void setRight(Node<T>* right);

};

#include "Node.hpp"
#endif
