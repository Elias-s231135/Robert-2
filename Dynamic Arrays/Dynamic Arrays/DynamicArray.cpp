#include "DynamicArray.h"

DynamicArray::DynamicArray(int initialSize)
{
	DynamicArray array;
	array.data = new array[initialSize];

}

DynamicArray::~DynamicArray()
{
	delete this;
}
