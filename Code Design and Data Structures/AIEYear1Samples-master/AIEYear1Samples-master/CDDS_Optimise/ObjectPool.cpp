#include "ObjectPool.h"

ObjectPool::ObjectPool(unsigned int size) : m_size(size), m_data(new Critter[size])
{
}

ObjectPool::~ObjectPool()
{
	delete[] m_data;
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
void ObjectPool::Deallocate(Critter sub, int pos)
{
	for (int i = pos; i <= m_used; i++)
	{
		m_data[i] = m_data[i + 1];
	}

	m_used -= 1;
}