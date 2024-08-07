#pragma once
#include "Item.h"

class LeftHandedMince : public Item
{
public:
	LeftHandedMince();
	const void Description();
	void Use();
private:
	bool obtained;
};