#pragma once
#include "Item.h"

class RightHandedMince : public Item
{
public:
	RightHandedMince();
	const void Description();
	void Use();
private:
	bool obtained;
};