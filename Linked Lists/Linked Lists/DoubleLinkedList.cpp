#include "DoubleLinkedList.h"
#include <iostream>

DoubleLinkedList::DoubleLinkedList()
{
   /* head = 0;
    tail = 0;*/
}

void DoubleLinkedList::PrintAllData()
{
  /*  std::cout << "head is: " << head->data << std::endl;
    std::cout << "tail is: " << tail->data << std::endl;*/
  
    Node* current = head;
    while (current != nullptr)
    {
        std::cout << current->data << std::endl;
        current = current->next;
    }
}

DoubleLinkedList DoubleLinkedList::PushFront(int frontValue)
{
    Node* temp = new Node();
    temp->data = frontValue;

    if (head == nullptr)
    {
        head = temp;
        temp->previous = nullptr;
    }
    else
    {
        //if head is not nullptr - node exists
        //tell current head that i'ts previous is our new temp node
        //tell our temp node that it's next is the current head
        //tell the dbl linked list that our new head is the temp node

        head->previous = temp;
        temp->next = head;
        head = temp;
    }


    if (tail == nullptr)
    {
        tail = temp;
        temp->next = nullptr;
    }

    return *this;
}

DoubleLinkedList DoubleLinkedList::PushBack(int backValue)
{
    Node* temp = new Node();
    temp->data = backValue;

    if (tail != nullptr)
    {
        tail->next = temp;
        temp->previous = tail;
        tail = temp;
    }
    else
    {
        tail = temp;
        //head should be set to temp as well
        head = temp;
    }


    return *this;
}

DoubleLinkedList DoubleLinkedList::Insert(iterator, int value)
{


    return *this;
}

int DoubleLinkedList::First()
{
    if (head != nullptr)
    {
        return head->data;
    }
}

int DoubleLinkedList::Last()
{
    if (tail != nullptr)
    {
        return tail->data;
    }
}

int DoubleLinkedList::Count()
{
    Node* current = head;

    int count = 0;

    while (current != nullptr)
    {
        count += 1;
        current = current->next;
    }

    return count;
}

DoubleLinkedList DoubleLinkedList::Remove(int matchingValue)
{
    Node* current = head;

    while (current != nullptr)
    {
        if (current->data == matchingValue)
        {
            current->next->previous = current->previous;
            current->previous->next = current->next;
        }

        current = current->next;
    }

    return *this;
}

DoubleLinkedList DoubleLinkedList::PopBack()
{
    Node* temp = tail;

    tail->previous->next = nullptr;
    tail = tail->previous;

    delete temp;

    return *this;
}

DoubleLinkedList DoubleLinkedList::PopFront()
{
    Node* temp = head;

    head->next->previous = nullptr;
    head = head->next;

    delete temp;

    return *this;
}

bool DoubleLinkedList::Empty()
{
    if (head == nullptr && tail == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

DoubleLinkedList DoubleLinkedList::Clear()
{
    Node* current = head->next;

    while (current != nullptr)
    {
        delete current->previous;   
        current = current->next;
    }
    delete this->tail;

    head = nullptr;
    tail = nullptr;
    return *this;

   /* Node* cNode = head;

    while (cNode != nullptr)
    {
        Node* temp;
    }*/
}
