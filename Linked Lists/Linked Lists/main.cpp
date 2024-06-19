#include "Node.h"
#include "DoubleLinkedList.h"

#include <iostream>

int main()
{
	DoubleLinkedList doubleLL;

	doubleLL.DoubleLinkedList::PushFront(7);

	doubleLL.DoubleLinkedList::PushFront(4);

	doubleLL.DoubleLinkedList::PushFront(9);

	doubleLL.DoubleLinkedList::PushBack(2);

	doubleLL.DoubleLinkedList::PushBack(8);

	doubleLL.DoubleLinkedList::Insert(doubleLL.head, 15);

	doubleLL.DoubleLinkedList::PrintAllData();

	std::cout << "first value is: " << doubleLL.DoubleLinkedList::First() << std::endl;

	std::cout << "last value is: " << doubleLL.DoubleLinkedList::Last() << std::endl;

	std::cout << "count is: " << doubleLL.DoubleLinkedList::Count() << std::endl;

	doubleLL.DoubleLinkedList::Remove(4);

	doubleLL.DoubleLinkedList::PopBack();

	doubleLL.DoubleLinkedList::PopFront();
		
	doubleLL.DoubleLinkedList::PrintAllData();

	std::cout << "current head is: " << doubleLL.head->data << std::endl;
	std::cout << "current tail is: " << doubleLL.tail->data << std::endl;

	doubleLL.DoubleLinkedList::Clear();

	//doubleLL.DoubleLinkedList::PushFront(1);

	//std::cout << "current head is: " << doubleLL.head->data << std::endl;
	//std::cout << "current tail is: " << doubleLL.tail->data << std::endl;

	doubleLL.DoubleLinkedList::PrintAllData();

	std::cout << "IsEmpty? (1 true, 0 false) \n" << doubleLL.Empty() << std::endl;
}