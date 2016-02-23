/**
*	@file : Stack.hpp
*	@author :  Vuong Nguyen
*	@date : 2015.03.04
*	Purpose: Implementation file of Stack Class. 
*/

#include <string>
#include "Node.h"

template <typename T>
Stack<T>::Stack()
{
	m_front = nullptr;
	m_size = 0;
}

template <typename T>
Stack<T>::~Stack()
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
bool Stack<T>::isEmpty() const
{
	if (m_size == 0)
	{
		return true;
	}
	else
		return false;
}

template <typename T>
int Stack<T>::size() const
{
	return (m_size);
}

template <typename T>
void Stack<T>::push(const T newEntry)
{
	Node<T>*temp = new Node<T>();
	temp -> setValue(newEntry);

	if(isEmpty())
	{
		m_front = temp;
		m_size = m_size + 1;
		
	}
	
	else 
	{
		temp -> setNext(m_front);
		m_front = temp;
		m_size = m_size + 1;
	}
	std::cout << newEntry << " is added to the stack.\n";
}

template <typename T>
T Stack<T>::pop() throw (PreconditionViolationException)
{
	T top;
	if (isEmpty()) {
		throw(PreconditionViolationException("Pop attempted on an empty stack."));
		
	} 
	else
	{
		Node<T>* temp = m_front;
		m_front = m_front->getNext();
		top = temp->getValue();
		delete (temp);
		m_size = m_size -1;
	}
	return (top);

}

template <typename T>
T Stack<T>::peek() const throw (PreconditionViolationException)
{
	if (isEmpty()) {
		throw(PreconditionViolationException("Peek attemped on an empty stack"));
		
	} 
	else
	{
		return (m_front->getValue());
	}
}	

template <typename T>
void Stack<T>::print() const
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

template <typename T>
bool Stack<T>::operator<(const StackInterface<T>& rhs) const
{
	return (size() < rhs.size());	
}

template <typename T>
bool Stack<T>::operator<= (const StackInterface<T>& rhs) const
{
	return (size() <= rhs.size());	

}

template <typename T>
bool Stack<T>::operator>(const StackInterface<T>& rhs) const
{
	return (size() > rhs.size());	

}

template <typename T>
bool Stack<T>::operator>=(const StackInterface<T>& rhs) const
{
	return (size() >= rhs.size());	

}

template <typename T>
bool Stack<T>::operator==(const StackInterface<T>& rhs) const
{
	return (size() == rhs.size());	

}

template <typename T>
bool Stack<T>::operator!=(const StackInterface<T>& rhs) const
{
	return (size() != rhs.size());	

}