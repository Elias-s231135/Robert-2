#include "DynamicArray.h"
#include <iostream>

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

DynamicArray DynamicArray::PrintAll()
{
	for (int i = 0; i < usedCount; i++)
	{
		std::cout << data[i] << ", ";
		/*std::cout << "UsedCount: " << usedCount << std::endl;
		std::cout << "capacity: " << capacity << std::endl;*/
	}
	std::cout << "\ncapacity is " << capacity << std::endl;
	std::cout << "usedCount is " << usedCount << std::endl;
	return usedCount;
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
	//capacity++;

	return *this;
}

DynamicArray DynamicArray::Unappend()
{
	usedCount -= 1;

	return *this;
}

DynamicArray DynamicArray::AddToMiddleOrdered(int pos, int value)
{
	// everything after pos moves 1+
	if (capacity == usedCount)
	{
		int* temp = new int[capacity * 2];
		for (int i = 0; i < usedCount; i++)
		{
			temp[i] = data[i];
		}
		delete[] data;
		data = temp;

		capacity = capacity * 2;
	}

	/*for (int j = pos; j < usedCount; j++)
	{
		temp[j] = data[j + 1];
	}*/

	//int* tempArray = new int[usedCount + 1];
	for (int j = usedCount; j >= pos; j--)
	{
		//tempArray[j] = data[j + 1];
		data[j + 1] = data[j];
	}

	usedCount += 1;

	data[pos] = value;

	return *this;
}

DynamicArray DynamicArray::AddToMiddleUnordered(int pos, int value)
{
	// pos moves to end

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

	//this[pos] = this[usedCount + 1];

	this->data[usedCount] = this->data[pos];

	data[pos] = value;

	usedCount += 1;
	/*this->data[pos] = value;*/

	return *this;
}

DynamicArray DynamicArray::RemoveFromMiddleUnordered(int pos)
{
	data[pos] = data[usedCount - 1];

	usedCount -= 1;
	
	return *this;
}

DynamicArray DynamicArray::RemoveFromMiddleOrdered(int pos)
{
	for (int i = pos; i <= usedCount; i++)
	{
		data[i] = data[i + 1];
	}

	//data[pos] = data[pos + 1];

	usedCount -= 1;

	return *this;
}

DynamicArray DynamicArray::AddCapacity(int add)
{
	capacity += add;

	return *this;
}

DynamicArray DynamicArray::RemoveCapacity(int remove)
{
	capacity -= remove;

	if (capacity < usedCount)
	{
		for (int i = usedCount; i > capacity; i--)
		{
			usedCount -= 1;
		}
	}

	return *this;
}

DynamicArray DynamicArray::Clear()
{
	usedCount = 0;

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
