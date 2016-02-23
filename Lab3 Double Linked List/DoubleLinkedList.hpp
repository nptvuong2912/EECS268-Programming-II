/**
*	@file : DoubleLinkedList.hpp
*	@author :  Vuong Nguyen
*	@date : 2015.02.25
*	Purpose: Implementation file of DoubleLinkedList Class. 
*/

#include <string>
#include "Node.h"

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList()
{
	m_front = nullptr;
	m_back = nullptr;
	m_size = 0;
}

template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
	if (!isEmpty())
	{
		while (m_front != nullptr)
		{
			Node<T>* temp = m_front;
			m_front = m_front->getNext();
			delete (temp);
		}
		delete(m_front);
	}
	else
	{
		std::cout << "List is empty.";
	}
}

template <typename T>
bool DoubleLinkedList<T>::isEmpty() const
{
	if (m_size == 0)
	{
		return true;
	}
	else
		return false;
}

template <typename T>
int DoubleLinkedList<T>::size() const
{
	return (m_size);
}

template <typename T>
void DoubleLinkedList<T>::pushFront(T value)
{
	Node<T>*temp = new Node<T>();
	temp -> setValue(value);

	if(isEmpty())
	{
		m_front = temp;
		m_back = temp;
		m_size = m_size + 1;
		
	}
	
	else 
	{
		temp -> setNext(m_front);
		m_front->setPrevious(temp);
		m_front = temp;
		m_size = m_size + 1;
	}
	
}

template <typename T>
void DoubleLinkedList<T>::pushBack(T value)
{
	Node<T>*temp = new Node<T>();
	temp -> setValue(value);

	if(isEmpty())
	{
		m_front = temp;
		m_back = temp;
		m_size = m_size + 1;
	}
	
	else 
	{
		temp -> setPrevious(m_back);
		m_back->setNext(temp);
		m_back = temp;
		m_size = m_size + 1;
	}
}

template <typename T>
bool DoubleLinkedList<T>::remove(T value)
{
	Node<T>* temp = find(value);
	if (temp == nullptr) {
		std::cout << "Value not found" << '\n';
		return false;
	}
	if (temp == m_front)
	{
		if (m_size == 1) {
			m_front = nullptr;
			m_back = nullptr;
			delete (temp);
		} else {
			m_front = m_front->getNext();
			m_front->setPrevious(nullptr);
			delete (temp);
		}
		m_size = m_size -1;
		return true;
	}
	else if (temp == m_back)
	{
		m_back = m_back->getPrevious();
		m_back->setNext(nullptr);	
		delete (temp);
		m_size = m_size -1;
		return true;
		
	}
	else if (temp != m_front && temp != m_back)
	{
		temp->getPrevious()->setNext(temp->getNext());
		temp->getNext()->setPrevious(temp->getPrevious());
		delete (temp);
		m_size = m_size -1;
		return true;
	}
	else
		return false;
}

template <typename T>
void DoubleLinkedList<T>::insertAhead(T listValue, T newValue) throw (std::runtime_error)
{
	Node<T>* temp = find(listValue);
	Node<T>*newV = new Node<T>();
	newV->setValue(newValue);

	if (temp == nullptr)
	{
		throw(std::runtime_error("Value not found."));
	}
	else if(temp == m_front)
	{
		newV->setNext(temp);
		temp->setPrevious(newV);
		m_front = newV;
	}
	else if (temp == m_back)
	{
		newV->setPrevious(temp->getPrevious());	
		temp->getPrevious()->setNext(newV);
		temp->setPrevious(newV);
		newV->setNext(temp);	
	}
	else if(temp != m_front)
	{
		newV->setNext(temp);
		newV->setPrevious(temp->getPrevious());
		temp->getPrevious()->setNext(newV);
		temp->setPrevious(newV);
	}
	m_size++;	
}

template <typename T>
void DoubleLinkedList<T>::insertBehind(T listValue, T newValue) throw (std::runtime_error)
{
	Node<T>* temp = find(listValue);
	Node<T>*newV = new Node<T>();
	newV->setValue(newValue);

	if(temp == nullptr)
	{
		throw(std::runtime_error("Value not found."));
	}
	
	else if(temp == m_back)
	{
		temp->setNext(newV);
		newV->setPrevious(temp);
		m_back = newV;
		
	}
	else if(temp != m_back)
	{
		newV->setPrevious(temp);
		newV->setNext(temp->getNext());
		temp->getNext()->setPrevious(newV);
		temp->setNext(newV);
	}
	m_size++;
}

template <typename T>
Node<T>*DoubleLinkedList<T>::find(T value) const
{
	Node<T>* temp = m_front;

	while (temp != nullptr)
	{
		if(value == temp->getValue())
		{
			return (temp);
		}
		temp = temp->getNext();
	}
	return (nullptr);
}

template <typename T>
void DoubleLinkedList<T>::printList() const
{
	Node<T>* temp = m_front;

	if (isEmpty())
	{
		std::cout<< "List Empty" << "\n";
	}
	else 
	{
		while (temp != nullptr)
		{
			std::cout << temp->getValue() << "\n" ;
			temp = temp->getNext();
		}
	}
}















