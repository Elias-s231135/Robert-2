#include "ObjectPool.h"

ObjectPool::ObjectPool(unsigned int size) : m_size(size), m_data(new Critter[size])
{
}

ObjectPool::~ObjectPool()
{
	delete[] m_data;
}

void ObjectPool::Allocate(Critter add)
{
	m_data[m_used] = add;

	m_used++;
}

void ObjectPool::Allocate(Critter add, int pos)
{
	for (int i = m_used; i >= pos; i--)
	{
		m_data[i + 1] = m_data[i];
	}

	m_used += 1;

	m_data[pos] = add;
}

void ObjectPool::Deallocate(Critter sub)
{
	//find critter and then deallocate it
}

void ObjectPool::Deallocate(int pos)
{
	//deallocate critter at given pos index

	//store m_used's data temporarily
	Critter temp = m_data[m_used - 1];

	//move pos to end
	m_data[m_used - 1] = m_data[pos];

	m_used--;

	m_data[pos] = temp;
}




void ObjectPool::Deallocate(Critter sub, int pos)
{
	for (int i = pos; i <= m_used; i++)
	{
		m_data[i] = m_data[i + 1];
	}

	m_used -= 1;
}