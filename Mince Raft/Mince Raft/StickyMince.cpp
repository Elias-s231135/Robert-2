#include "StickyMince.h"
#include <iostream>

using namespace std;

StickyMince::StickyMince()
{
}

const void StickyMince::Description()
{
	cout << "A piece of mince that appears very sticky. If it wasn't in this mince cave, it would probably accumulate a lot of junk." << endl;
}

void StickyMince::Use()
{
	cout << "You poke it, and it clings to your finger. It releases after a firm shake." << endl;
}
