#include "HashTable.h"

#include <iostream>


int main()
{
	HashTable ha(3);

	ha.AddTo("one", 1);
	ha.AddTo("ANCIENTHOOP", 2);
	ha.AddTo("seven", 1300655506);

	ha["seven"];
	std::cout << ha.operator[]("seven") << std::endl;

	ha.PrintAll();

	ha.Remove("seven");

	ha.PrintAll();

	ha.Clear();

	std::cout << "Clear works" << std::endl;
}