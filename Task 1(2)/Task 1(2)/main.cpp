#include <iostream>
#include "StringTester.h"

int main()
{
	String st("Hello, World");

	std::cout << "Your letter is " << st.CharacterAt(1) << std::endl;

	if (st.EqualTo("Hello, World"))
	{
		std::cout << "true :)" << std::endl;
	}
	else
	{
		std::cout << "false >:(" << std::endl;
	}
}