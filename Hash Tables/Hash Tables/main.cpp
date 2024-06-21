#include "HashTable.h"

int main()
{
	HashTable ha(3);

	ha.AddTo("ELDENERRING", 1);
	ha.AddTo("ANCIENTHOOP", 2);
	ha.AddTo("", 0);

	ha.PrintAll();
}