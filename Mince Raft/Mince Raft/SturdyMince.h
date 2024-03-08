#pragma once
#include "Item.h"

class SturdyMince : public Item
{
public:
	SturdyMince();
	const void Description();
	void Use();
private:
	bool obtained;
};