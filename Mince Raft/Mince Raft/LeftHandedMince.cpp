#include "LeftHandedMince.h"
#include <iostream>

using namespace std;

LeftHandedMince::LeftHandedMince()
{
}

const void LeftHandedMince::Description()
{
	cout << "A piece of mince that is shaped to fit perfectly in a left hand." << endl;
}

void LeftHandedMince::Use()
{
	cout << "You hold it in your left hand. Nothing happens. You hold it in your right hand. You drop the mince as your hand seizes in pain." << endl;
}
