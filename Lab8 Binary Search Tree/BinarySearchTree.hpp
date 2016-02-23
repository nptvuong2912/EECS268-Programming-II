/**
*	@file : BinarySearchTree.hpp
*	@author :  Vuong Nguyen
*	@date : 2015.04.15
*	Purpose: Implementation file of Binary Search Tree Class. 
*/

#include <string>
#include "Node.h"


template<typename T>
BinarySearchTree<T>::BinarySearchTree()
{
	m_root = nullptr;
	
}


template<typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& other)
{
	if(other.m_root == nullptr)
	{
		m_root == nullptr;
	}
	else
	{		
		m_root = new Node<T>(*(other.m_root));
	}
}


template<typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
	if(!isEmpty())
	{
		deleteTree(m_root);
	}
	else
	{
		std::cout << "There are no nodes in the tree. \n";
	}
	
}


template<typename T>
BSTI<T>* BinarySearchTree<T>::clone()
{
	BSTI<T>* copy = new BinarySearchTree<T>(*this);
	return copy;
}

template<typename T>
bool BinarySearchTree<T>::isEmpty() const
{
	if (m_root == nullptr)
	{
		return true;
	}
	else
		return false;
}


template<typename T>
bool BinarySearchTree<T>::add(T value)
{
	if(m_root == nullptr)
	{
		m_root = new Node<T>;
		m_root->setValue(value);
		return true;	
	}
	else
	{ 
		if(add(value,m_root))
			return true;
		else
			return false;
	}
}

template<typename T>
void BinarySearchTree<T>::printTree(Order order) const
{
	
	if(isEmpty())
	{
		std::cout << "Tree empty. \n";
	}
	else if(order == PRE_ORDER)
	{
		this->printTree(m_root, PRE_ORDER);
	}
	else if(order == IN_ORDER)
	{
		this->printTree(m_root, IN_ORDER);
	}
	else if(order == POST_ORDER)
	{
		this->printTree(m_root, POST_ORDER);
	}
}


template<typename T>
void BinarySearchTree<T>::sortedPrint() const
{
	if(isEmpty())
	{
		std::cout << "Tree is empty. \n";
	}
	else
	{
		this->printTree(m_root,IN_ORDER);	
	}
}		



template<typename T>
T BinarySearchTree<T>::search(T value) const throw (ValueNotFoundException)
{
	this->search(value, m_root);
}


template<typename T>
bool BinarySearchTree<T>::add(T value, Node<T>* subTree)
{
	
	if(value < subTree->getValue())
	{
		if(subTree->getLeft() == nullptr)
		{
			Node<T>* temp = new Node<T>;
			temp->setValue(value);
			subTree->setLeft(temp);
		}
		else
		{
			add(value, subTree->getLeft());
		}

	}
	else if (value > subTree->getValue())
	{
		if(subTree->getRight() == nullptr)
		{
			Node<T>* temp = new Node<T>;
			temp->setValue(value);
			subTree->setRight(temp);
		}
		else
		{
			add(value, subTree->getRight());
		}
	}
	else if (value == subTree->getValue())
	{
		return false;
	}

	return true;
}


template<typename T>
void BinarySearchTree<T>::deleteTree(Node<T>* subTree)
{
	if(subTree != nullptr)
	{
		Node<T>* temp = subTree;
		deleteTree(subTree->getLeft());
		deleteTree(subTree->getRight());
		delete (temp);
	}
		
}


template<typename T>
T BinarySearchTree<T>::search(T value, Node<T>* subTree)const throw( ValueNotFoundException ) 
{
	if(subTree->getValue() == value)
	{
		return value;
	}

	if(subTree->getLeft() == nullptr && subTree->getRight() == nullptr)
	{
		throw(ValueNotFoundException("The value is not found."));
	}
	if(value < subTree->getValue())
	{
		if(subTree->getLeft() == nullptr)
		{
			throw(ValueNotFoundException("The value is not found."));
		}
		return search(value, subTree->getLeft());
	}
	if (value >subTree->getValue())
	{
		if(subTree->getRight() == nullptr)
		{
			throw(ValueNotFoundException("The value is not found."));
		}
		return search(value, subTree->getRight());	
	}
}


template<typename T>
void BinarySearchTree<T>::printTree(Node<T>* subTree, Order order) const
{
	
    if (subTree!= nullptr)
    {
        if (order == PRE_ORDER)
        {
            std::cout << subTree->getValue() << " ";
            printTree(subTree->getLeft(), order);
            printTree(subTree->getRight(), order);
        }

        if (order == IN_ORDER)
        {
            printTree(subTree->getLeft(), order);
            std::cout << subTree->getValue() << " ";
            printTree(subTree->getRight(), order);
        }

        if (order == POST_ORDER)
        {
            printTree(subTree->getLeft(), order);
            printTree(subTree->getRight(), order);
            std::cout << subTree->getValue() << " ";
        }
    }
}















