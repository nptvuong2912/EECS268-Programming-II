/**
*	@file : Node.hpp
*	@author :  Vuong Nguyen
*	@date : 2015.02.25
*	Purpose: Implementation file of Node Class. 
*/



template <typename T>
Node<T>::Node()
{
	m_value = T();
	m_next = nullptr;
	m_previous = nullptr;
}

//Set methods
template <typename T>
void Node<T>::setValue(T value)
{
	m_value = value;
}

template <typename T>
void Node<T>::setNext(Node<T>* next)
{
	m_next = next;
}

template <typename T>
void Node<T>::setPrevious(Node<T>* prev)
{
	m_previous = prev;
}

//Get methods
template <typename T>
T Node<T>::getValue()
{
	return m_value;
}

template <typename T>
Node<T>* Node<T>::getNext()
{
	return m_next;
}

template <typename T>
Node<T>* Node<T>::getPrevious()
{
	return m_previous;
}
