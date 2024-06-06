#include "DynamicArray.h"

DynamicArray::DynamicArray()		//(int initialSize)
{
	//DynamicArray array;
	//array.data = new array[initialSize];

	data = new int[2] {1};

}

DynamicArray::DynamicArray(int a)
{
	this->data = new int[a];
	this->capacity = a;
	this->usedCount = 0;
}

DynamicArray::DynamicArray(DynamicArray& m_array)
{
	this->data = new int[m_array.capacity];
	this->capacity = m_array.capacity;
	this->usedCount = m_array.usedCount;

	// for every element in m_array
	for (int i = 0; i < m_array.usedCount; i++)
	{
		// add other data to this data
		this->data[i] = m_array.data[i];
	}
}

DynamicArray::~DynamicArray()
{
	delete data;
}

DynamicArray DynamicArray::Append(int m_new)
{
	if (capacity == usedCount)
	{
		int* temp = new int[usedCount * 2];
		for (int i = 0; i < usedCount; i = i + 1)
		{
			temp[i] = data[i];
		}

		delete[] data;
		data = temp;

		capacity = capacity * 2;
	}

	data[usedCount] = m_new;
	usedCount += 1;

	return *this;
}

DynamicArray DynamicArray::Unappend()
{
	usedCount -= 1;

	return *this;
}

void DynamicArray::operator=(const DynamicArray assign)
{
	delete[] data;
	data = new int[assign.capacity];

	capacity = assign.capacity;

	usedCount = assign.usedCount;
}

//CreateArray(initialSize)
//{
//	DynamicArray array;
//	array.data = 
//}
