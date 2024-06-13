#pragma once

#include "DoubleLinkedList.h"

class Node : public DoubleLinkedList
{
public:		// Variables

	int data;
	Node* previous;
	Node* next;

public:		// Functions

	Node();

};

