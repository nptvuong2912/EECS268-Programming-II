/**
*	@file : BinarySearchTree.h
*	@author :  Vuong Nguyen
*	@date : 2015.04.14
*	Purpose: Header file of BinarySarchTree Class. 
*/

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include "Node.h"
#include "BSTI.h"
#include <iostream>
#include <stdexcept>

template <typename T>

class BinarySearchTree: public BSTI<T>
{
	private:
	Node<T>* m_root;

	/**
	*  @pre value is a valid T
	*  @post adds the value to the correct branch of the subTree
	*  @return true if add operation was successful
	*/
	bool add(T value, Node<T>* subTree);
	
	/**
	*  @pre none
	*  @post deletes the right, left sub trees and the root node of the passed-in subTree
	*  @return none
	*/
	void deleteTree(Node<T>* subTree);

	/**
	*  @pre none
	*  @post None
	*  @return returns the value if in the tree, throws exception otherwise
	*/
	T search(T value, Node<T>* subTree) const throw(ValueNotFoundException);
	
	/**
	*  @pre none
	*  @post Print the tree in specified order using subTree and order.
	*  @return none
	*/
	void printTree(Node<T>* subTree, Order order) const;


	
	public:
	
	/**
	*  @pre None
	*  @post Creates and initializes an instance
	*  @return an initialized BinarySearchTree
	*/
	BinarySearchTree();

	/**
	*  @pre None
	*  @post Creates a deep copy of the other BST
	*  @return a copy BinarySearchTree
	*/
	BinarySearchTree(const BinarySearchTree<T>& other);

	/**
	*  @pre A BSTI exists
	*  @post deletes the entire tree (containing the nodes)
	*  @return 
	*/
	~BinarySearchTree();

	/**
	*  @pre in a valid state
	*  @post creates a deep copy of the tree
	*  @return a pointer to the deep copy
	*/
	BSTI<T>* clone();

	/**
	*  @pre none
	*  @post none
	*  @return true only if there is no nodes in the tree
	*/
	bool isEmpty() const;

	/**
	*  @pre value is a valid T
	*  @post Add a new node into the tree based
	*  @return false if the value couldn't be added
	*/
	bool add(T value);

	
	/**
	*  @pre none
	*  @post Print the contents of the tree to the console in specified order
	*  @return none
	*/
	void printTree(Order order) const;

	/**
	*  @pre none
	*  @post print the contents of the tree in in-oder (sorted)
	*  @return none
	*/
	void sortedPrint() const;
	
	/**
	*  @pre type T is comparable by the == operator
	*  @post None
	*  @return returns the value if in the tree, throws exception otherwise
	*/
	T search(T value) const throw(ValueNotFoundException);

	
};
#include "BinarySearchTree.hpp"
#endif


	

	

	
	
