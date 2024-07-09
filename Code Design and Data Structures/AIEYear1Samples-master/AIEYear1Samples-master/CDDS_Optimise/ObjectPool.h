#pragma once

#include "Critter.h"

class ObjectPool : public Critter 
{
public:

	ObjectPool(unsigned int size);
	
	~ObjectPool();

	void Allocate(Critter add, int pos);

	void Deallocate(Critter sub, int pos);

private:

	unsigned int m_size = 0;
	Critter* m_data = nullptr;
	int m_used = 0;
};

