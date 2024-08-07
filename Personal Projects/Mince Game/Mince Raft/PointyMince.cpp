#include "PointyMince.h"
#include <iostream>

using namespace std;

PointyMince::PointyMince()
{
}

const void PointyMince::Description()
{
	cout << "A piece of mince with a long sharp point. Upon further inspection, it's covered in smaller spikes." << endl;
}

void PointyMince::Use()
{
	cout << "Ouch! It was pointy. (-0.0001 health)" << endl;
}
