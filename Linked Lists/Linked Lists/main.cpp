#include "Node.h"
#include "DoubleLinkedList.h"

#include <iostream>

int main()
{
	DoubleLinkedList doubleLL;

	doubleLL.PushFront(7);

	doubleLL.PushFront(4);

	doubleLL.PushFront(9);

	doubleLL.PushFront(6);

	doubleLL.PushBack(2);

	doubleLL.PushBack(8);

	doubleLL.Insert(doubleLL.head, 15);

	doubleLL.Erase(doubleLL.head);

	doubleLL.PrintAllData();

	std::cout << "beginning is: " << doubleLL.Begin().Current() << std::endl;

	std::cout << "ending is: nullptr" << std::endl;
	
	std::cout << "first value is: " << doubleLL.First() << std::endl;

	std::cout << "last value is: " << doubleLL.Last() << std::endl;

	std::cout << "count is: " << doubleLL.Count() << std::endl;

	doubleLL.Remove(4);

	doubleLL.PopBack();

	doubleLL.PopFront();
		
	doubleLL.PrintAllData();

	std::cout << "current head is: " << doubleLL.head->data << std::endl;
	std::cout << "current tail is: " << doubleLL.tail->data << std::endl;

	doubleLL.Clear();

	//doubleLL.DoubleLinkedList::PushFront(1);

	//std::cout << "current head is: " << doubleLL.head->data << std::endl;
	//std::cout << "current tail is: " << doubleLL.tail->data << std::endl;

	doubleLL.DoubleLinkedList::PrintAllData();

	std::cout << "IsEmpty? (1 true, 0 false) \n" << doubleLL.Empty() << std::endl;
}