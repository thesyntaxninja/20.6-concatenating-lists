// 20.6 Node.h
// Description: Problem 2 of 2 due week 9
// Programmer: Parker Esmay
// Date: 03/23/2015

#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

template<typename T> class List;

template<typename T>
class Node
{
	friend class List<T>; 
	public:
		Node(const T &); // constructor
		T getData() const; // return nodeData in Node
		// set nextPtr to next
		void setNextPtr(Node *next)
		{
			nextPtr = next;
		} 

		// return nextPtr
		Node *getNextPtr() const
		{	
			return nextPtr;
		} 
	
	private:
		T nodeData; 
		Node *nextPtr; // next Node in list
};

// constructor
template<typename T>
Node<T>::Node(const T &info)
{
	nodeData = info;
	nextPtr = 0;
} 

// return a copy of the nodeData in the Node
template<typename T>
T Node<T>::getData() const
{
	return nodeData;
} 

#endif

