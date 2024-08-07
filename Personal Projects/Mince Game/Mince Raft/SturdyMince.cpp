#include "SturdyMince.h"
#include <iostream>

using namespace std;

SturdyMince::SturdyMince()
{
}

const void SturdyMince::Description()
{
	cout << "A piece of mince that is hard to break. it appears to be what the fortress and the Mince Meister's armour are made out of." << endl;
}

void SturdyMince::Use()
{
	cout << "You hit it with all your might. It stands firm." << endl;
}
