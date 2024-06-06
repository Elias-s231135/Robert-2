#pragma once
class DynamicArray
{
public:
	DynamicArray();			//(int initialSize)
	DynamicArray(int m_array);
	DynamicArray(DynamicArray &m_array);
	~DynamicArray();

	DynamicArray Append(int m_new);
	DynamicArray Unappend();

	//CreateArray(initialSize);

public: //variables
	int* data;
	int capacity;
	int usedCount;

public:
	void operator=(const DynamicArray assign);
};

