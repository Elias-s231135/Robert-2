#include "RightHandedMince.h"
#include <iostream>

using namespace std;

RightHandedMince::RightHandedMince()
{
}

const void RightHandedMince::Description()
{
    cout << "A piece of mince that fits perfectly in a right hand." << endl;
}

void RightHandedMince::Use()
{
    cout << "You hold it in your right hand. Nothing happens. You hold it in your left hand. You drop the mince as your hand seizes in pain." << endl;
}
