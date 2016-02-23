/**
*	@file : BSTI.h
*	@author :  Vuong Nguyen
*	@date : 2015.04.10
*	Purpose: Interface of BST Class. 
*/

#ifndef BSTI_H
#define BSTI_H

#include "Node.h"
#include "ValueNotFoundException.h"
#include <iostream>
#include <stdexcept>
#include <string>

enum Order {PRE_ORDER, IN_ORDER, POST_ORDER};

template<typename T>

class BSTI	
{
	public:
	/**
	*  @pre A BSTI exists
	*  @post deletes the entire tree (containing the nodes)
	*  @return 
	*/
	virtual ~BSTI() {};
	
	/**
	*  @pre in a valid state
	*  @post creates a deep copy of the tree
	*  @return a pointer to the deep copy
	*/
	virtual BSTI<T>* clone() = 0;

	/**
	*  @pre none
	*  @post none
	*  @return true only if there is no nodes in the tree
	*/
	virtual bool isEmpty() const = 0;
	
	/**
	*  @pre value is a valid T
	*  @post Add a new node into the tree based
	*  @return false if the value couldn't be added
	*/
	virtual bool add(T value) = 0;

	/**
	*  @pre type T is comparable by the ==e operator
	*  @post None
	*  @return returns the value if in the tree, throws exception otherwise
	*/
	virtual T search(T value) const throw(ValueNotFoundException) = 0;


	/**
	*  @pre none
	*  @post Print the contents of the tree to the console in specified order
	*  @return none
	*/
	virtual void printTree(Order order) const = 0;

	/**
	*  @pre none
	*  @post print the contents of the tree in in-oder (sorted)
	*  @return none
	*/
	virtual void sortedPrint() const = 0;


};
#endif
