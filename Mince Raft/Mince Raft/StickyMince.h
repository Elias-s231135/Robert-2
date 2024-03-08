#pragma once
#include "Item.h"

class StickyMince : public Item
{
public:
	StickyMince();
	const void Description();
	void Use();
private:
	bool obtained;
};