#pragma once

#include "Node.h"

class DoubleLinkedList
{
public:												// Linked List Variables

	Node* head;
	Node* tail;
public:
	class LinkListIterator
	{
		friend class DoubleLinkedList;

	private:							// iterator variables
		Node* currentNode;
	public:								// iterator functions
		LinkListIterator(Node* node)
		{
			currentNode = node;
		};
		
		int Current()
		{
			return currentNode->data;
		}

		bool MoveNext()
		{
			if (currentNode->next != nullptr)
			{
				currentNode = currentNode->next;
				return true;
			}
			else
			{
				return false;
			}
		}

		bool MovePrev()
		{
			if (currentNode->previous != nullptr)
			{
				currentNode = currentNode->previous;
				return true;
			}
			else
			{
				return false;
			}
		}

		void operator++()
		{
			//logical step forward in the data container
			MoveNext();
		}

		void operator--()
		{
			//logical step backwards in the data container
			MovePrev();
		}
	};
public:												// (De)Constructors
	
	DoubleLinkedList();

public:												// Functions

	void PrintAllData();

	DoubleLinkedList PushFront(int frontValue);		// Add a new value to the front of the list
	DoubleLinkedList PushBack(int backValue);		// Add a new value to the end of the list
	
	DoubleLinkedList Insert(LinkListIterator prev, int value);	// Add a new value one-past the specified iterator location
	
	DoubleLinkedList Begin();						// return an iterator to the first element
	DoubleLinkedList End();							// return an iterator to a null element

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

