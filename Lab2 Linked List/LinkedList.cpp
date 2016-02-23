/**
*	@file : LinkedList.cpp
*	@author :  Vuong Nguyen
*	@date : 2015.02.12
*	Purpose: Implementation file of LinkedList Class. 
*/

#include "LinkedList.h"

LinkedList::LinkedList()
{
	m_front = nullptr;
	m_size = 0;
}

bool LinkedList::isEmpty() const
{
	if (m_front == nullptr)
	{
		return true;
	}
	else
		return false;
}

int LinkedList::size() const
{
	return (m_size);
}

LinkedList::~LinkedList()
{
	if (!isEmpty())
	{
		while (m_front != nullptr)
		{
			Node* temp = m_front;
			m_front = m_front->getNext();
			delete (temp);
		}
		delete(m_front);
	}
	
	
}


bool LinkedList::search(int value) const
{
	Node* temp = new Node();
	temp = m_front;

	while (value != temp->getValue())
	{
		temp = temp->getNext();
		if (temp == nullptr)
		{
			return false;
		}
		
	}
	return true;
	
}
void LinkedList::printList() const
{
	Node* temp;
	temp = m_front;
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

void LinkedList::addFront(int value)
{

	Node* temp = m_front;
	m_front = new Node();
	m_front->setValue(value);
	m_front->setNext(temp);
	m_size ++;
}

void LinkedList::addBack(int value)
{
	if (isEmpty()) 
	{
		m_front = new Node();
		m_front->setValue(value);
		m_front->setNext(nullptr);
	}
	else
	{
		Node* last;
		last = m_front;
		while(last->getNext() != nullptr)
		{
			last = last->getNext();
		}
		Node* temp = new Node();
		temp->setValue(value);
		temp->setNext(nullptr);
		last->setNext(temp);
	}
	m_size ++;
}

bool LinkedList::removeBack()
{
	if(isEmpty())
		return false;
	else if(m_size == 1)
	{
		delete(m_front);
		m_front = nullptr;
		m_size = m_size -1;
		return true;
	}
	else
	{
		Node* temp = m_front;
		while (temp->getNext()->getNext() != nullptr)
		{
			temp = temp->getNext();
		}
		delete (temp->getNext());
		temp->setNext(nullptr);
		m_size = m_size -1;
		return true;
	}
}

bool LinkedList::removeFront()
{
	if(isEmpty())
	{
		return false;
	}
	else
	{
		Node* temp = m_front;
		m_front = m_front->getNext();
		delete (temp);
		m_size = m_size -1;
		return true;
	}
}

