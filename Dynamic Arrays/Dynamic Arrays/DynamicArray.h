#pragma once
class DynamicArray
{
public:
	DynamicArray();			//(int initialSize)
	DynamicArray(int m_array);
	DynamicArray(DynamicArray &m_array);
	~DynamicArray();

	DynamicArray PrintAll();

	DynamicArray Append(int m_new);
	DynamicArray Unappend();

	DynamicArray AddToMiddleOrdered(int pos, int value);
	DynamicArray AddToMiddleUnordered(int pos, int value);
	
	DynamicArray RemoveFromMiddleUnordered(int pos);
	DynamicArray RemoveFromMiddleOrdered(int pos);

	DynamicArray AddCapacity(int add);
	DynamicArray RemoveCapacity(int remove);

	DynamicArray Clear();

	//CreateArray(initialSize);

public: //variables
	int* data;
	int capacity;
	int usedCount;

public:
	void operator=(const DynamicArray assign);
};

