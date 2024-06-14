#pragma once

#include "Node.h"

class DoubleLinkedList
{
public:
	class LinkListIterator
	{
	private:
		Node* currentNode;
	public:
		int Current()
		{
			return currentNode->data;
		}

		bool MoveNext()
		{
			if ()
			{
				return true
			}
			return false;
		}

		bool MovePrev()
		{
			return false;
		}

		void operator++()
		{
			//logical step forward in the data container
		}

		void operator--()
		{
			//logical step backwards in the data container
		}
	};

public:												// Variables

	Node* head;
	Node* tail;

public:												// (De)Constructors
	
	DoubleLinkedList();

public:												// Functions

	void PrintAllData();

	DoubleLinkedList PushFront(int frontValue);		// Add a new value to the front of the list
	DoubleLinkedList PushBack(int backValue);		// Add a new value to the end of the list
	
	DoubleLinkedList Insert(iterator, int value);	// Add a new value one-past the specified iterator location
	
//	DoubleLinkedList Begin();						// return an iterator to the first element
//	DoubleLinkedList End();							// return an iterator to a null element

	int First();									// return the first element by value, assert if no elements
	int Last();										// return the last element by value, assert if no elements

	int Count();									// return how many elements exist in the list

//	DoubleLinkedList Erase(iterator);				// remove an element by its iterator

	DoubleLinkedList Remove(int matchingValue);		// remove all elements with matching value

	DoubleLinkedList PopBack();						// remove the last element
	DoubleLinkedList PopFront();					// remove the first element

	bool Empty();									// return a Boolean, true if the list is empty, false otherwise

	DoubleLinkedList Clear();						// remove all elements from the list
};

