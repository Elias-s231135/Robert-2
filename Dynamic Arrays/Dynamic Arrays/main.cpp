#include <iostream>
#include "DynamicArray.h"

using namespace std;

int main()
{

	/*DynamicArray dyAr[5] = {8, 5, 7, 2, 4};*/

	DynamicArray dyAr(5);

	/*cout << dyAr.data << endl;
	cout << dyAr.capacity << endl;
	cout << dyAr.usedCount << endl;*/
	
	dyAr.DynamicArray::PrintAll();
	
	dyAr.DynamicArray::Append(8);

	dyAr.DynamicArray::Append(5);

	dyAr.DynamicArray::Append(7);

	dyAr.DynamicArray::Append(2);

	dyAr.DynamicArray::Append(4);

	dyAr.DynamicArray::Append(3);

	dyAr.DynamicArray::Append(6);

	dyAr.DynamicArray::PrintAll();

	dyAr.DynamicArray::Unappend();

	dyAr.DynamicArray::PrintAll();

	dyAr.DynamicArray::AddToMiddleOrdered(3, 1);

	dyAr.DynamicArray::PrintAll();

	dyAr.DynamicArray::AddToMiddleUnordered(4, 9);

	dyAr.DynamicArray::PrintAll();

	dyAr.DynamicArray::RemoveFromMiddleUnordered(5);

	dyAr.DynamicArray::PrintAll();

	dyAr.DynamicArray::RemoveFromMiddleOrdered(2);

	dyAr.DynamicArray::PrintAll();

	dyAr.DynamicArray::AddCapacity(5);

	dyAr.DynamicArray::PrintAll();

	dyAr.DynamicArray::RemoveCapacity(10);

	dyAr.DynamicArray::PrintAll();

	dyAr.DynamicArray::Clear();

	dyAr.DynamicArray::PrintAll();

	/*{
		cout << data << endl;
	};*/

}