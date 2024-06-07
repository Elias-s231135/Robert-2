#include <iostream>
#include "DynamicArray.h"

using namespace std;

int main()
{

	/*DynamicArray dyAr[5] = {4, 5, 2, 7, 1};*/

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

	/*{
		cout << data << endl;
	};*/

}