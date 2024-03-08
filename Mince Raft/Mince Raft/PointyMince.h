#pragma once
#include "Item.h"

class PointyMince : public Item
{
public:
	PointyMince();
	const void Description();
	void Use();
private:
	bool obtained;
};
