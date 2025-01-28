#pragma once

#include "Critter.h"

class ObjectPool : public Critter 
{
public:

	ObjectPool(unsigned int size);
	
	~ObjectPool();

	void Allocate(Critter add);

	void Allocate(Critter add, int pos);

	void Deallocate(Critter sub);

	void Deallocate(int pos);

	void Deallocate(Critter sub, int pos);

	int CurrentUsed() { return m_used; }

	Critter* GetAlive() { return m_data; }

	int CurrentSize() { return m_size; }

private:

	unsigned int m_size = 0;
	Critter* m_data = nullptr;
	int m_used = 0;
};

