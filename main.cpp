// 20.6 main.cpp
// Description: Problem 2 of 2 due week 9
// Programmer: Parker Esmay
// Date: 03/23/2015

// (Concatenating Lists) Write a program that concatenates two linked list objects of characters. The program
// should include function concatenate, which takes references to both list objects as arguments and concatenates
// the second list to the first list.

#include <iostream>
#include <cstdlib>
#include <conio.h>
#include "List.h"

using namespace std;

int main(int argc, char** argv) 
{
	List<char> firstList; 
	List<char> secondList; 
	char c;

	// assign characters
	for (c = 'a'; c <= 'g'; c++)
	firstList.insertFront(c); // insert at front of list

	// call function print to print the list
	firstList.print();

	// assign from f to j into second list
	for (c = 'f'; c <= 'j'; c++)
	secondList.insertBack(c); // insert in back of list

	secondList.print();

	// concatenate secondList to the firstList
	concatenate(firstList, secondList);
	cout << "firstList after concatenation:\n";
	firstList.print();
	
	getch();
	 
	return 0;
}
