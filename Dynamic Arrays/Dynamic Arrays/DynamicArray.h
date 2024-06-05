#pragma once
class DynamicArray
{
public:
	DynamicArray();			//(int initialSize)
	DynamicArray(int m_array);
	DynamicArray(DynamicArray &m_array);
	~DynamicArray();



	//CreateArray(initialSize);

public: //variables
	int* data;
	int capacity;
	int usedCount;

public:
	void operator=(const DynamicArray assign);
};

