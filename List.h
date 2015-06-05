// 20.6 List.h
// Description: Problem 2 of 2 due week 9
// Programmer: Parker Esmay
// Date: 03/23/2015


#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

#include <new>
#include "Node.h"

template<typename T>
class List
{
	public:
		List(); // default constructor
		List(const List<T> &); // copy constructor
		~List(); // destructor

		void insertFront(const T &);
		void insertBack(const T &);
		bool removeFront(T &);
		bool removeBack(T &);
		bool isEmpty() const;
		void print() const;
		void concatenate(List<T> &first, List<T> &second);
		
	protected:
		Node<T> *firstPtr; // pointer first node
		Node<T> *lastPtr; // pointer last node

		Node<T> *getNewNode(const T &);
}; 


// default constructor
template<typename T>
List<T>::List()
{
	firstPtr = lastPtr = 0;
} 

// copy constructor
template<typename T>
List<T>::List(const List<T> &copy)
{
	firstPtr = lastPtr = 0;

	Node<T> *currentPtr = copy.firstPtr;

	while (currentPtr != 0)
	{
		insertBack(currentPtr->nodeData);
		currentPtr = currentPtr->nextPtr;
 	} 
} 

// destructor
template<typename T>
List<T>::~List()
{
	if (!isEmpty()) 
	{
		cout << endl << "Destroy nodes: ";
		
		Node<T> *currentPtr = firstPtr;
		Node<T> *tempPtr;
		
		while (currentPtr != 0) 
		{
			tempPtr = currentPtr;
			cout << tempPtr->nodeData << ' ';
			currentPtr = currentPtr->nextPtr;
			delete tempPtr;
		}
	}
	
	cout << "\n";
} 

// Insert node at front of list
template<typename T>
void List<T>::insertFront(const T &value)
{
	Node<T> *newPtr = getNewNode(value);
	
	if ( isEmpty() ) 
	firstPtr = lastPtr = newPtr;
	else 
	{
 		newPtr->nextPtr = firstPtr;
		firstPtr = newPtr;
	} 
} 

// Insert node at back of list
template<typename T>
void List<T>::insertBack(const T &value)
{
	Node<T> *newPtr = getNewNode(value);

	if (isEmpty())
		firstPtr = lastPtr = newPtr;
	else 
	{
		lastPtr->nextPtr = newPtr;
		lastPtr = newPtr;
	} 
} 

// Delete node from front of list
template<typename T>
bool List<T>::removeFront(T &value)
{
	if (isEmpty()) 
		return false; 
	else
	{
		Node<T> *tempPtr = firstPtr;

		if (firstPtr == lastPtr)
		firstPtr = lastPtr = 0;
		else
			firstPtr = firstPtr->nextPtr;

		value = tempPtr->nodeData;

		delete tempPtr;
		return true;
	} 
}

// Delete node from back of list
template<typename T>
bool List< T >::removeBack(T &value)
{
	if (isEmpty())
		return false; 
	else
	{
		Node<T> *tempPtr = lastPtr;

		if (firstPtr == lastPtr)
		firstPtr = lastPtr = 0;
		else
		{
			Node<T> *currentPtr = firstPtr;

			while (currentPtr->nextPtr != lastPtr)
			currentPtr = currentPtr->nextPtr;

			lastPtr = currentPtr;
			currentPtr->nextPtr = 0;
		}

		value = tempPtr->nodeData;
		delete tempPtr;
		return true;
	} 
} 

// Check if list is empty
template< typename T >
bool List<T>::isEmpty() const
{
	return firstPtr == 0;
} 

// Return a pointer to a new node
template<typename T>
Node<T> *List<T>::getNewNode(const T &value)
{
	Node<T> *ptr = new Node<T>(value);
	return ptr;
} 

// Print contents of the list
template<typename T>
void List<T>::print() const
{
	if (isEmpty())
	{
		cout << "The list is empty\n\n";
		return;
	} 

	Node<T> *currentPtr = firstPtr;

	cout << "The list: ";
	
	while (currentPtr != 0) 
	{
		cout << currentPtr->nodeData << ' ';
		currentPtr = currentPtr->nextPtr;
	} 
	
	cout << "\n\n";
} 

// concatenate list 1 and list 2
template<typename T>
void concatenate(List<T> &first, List<T> &second)
{
	List<T> temp(second); // create a copy 
	T value; 

	while (!temp.isEmpty())
	{
		temp.removeFront(value); // remove from temporary list
		first.insertBack(value); // insert at back of first list
	} 
} 

#endif




