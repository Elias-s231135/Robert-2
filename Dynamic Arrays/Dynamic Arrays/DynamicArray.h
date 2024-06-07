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

	DynamicArray AddToMiddleU(int pos, int value);
	DynamicArray AddToMiddleO(int pos, int value);

	//CreateArray(initialSize);

public: //variables
	int* data;
	int capacity;
	int usedCount;

public:
	void operator=(const DynamicArray assign);
};

