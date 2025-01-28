#include <iostream>

using namespace std;

int main()
{
	int current = 0;
	float runningTotal = 0;
	int runningCount = 0;
	char currentChar = 0;

	bool inputting = true;

	while (inputting)
	{
		std::cout << "PLease input an integer to add to the running total" << std::endl;

		std::cin >> current;

		if (std::cin.fail()) //If user doesn't input an integer
		{
			std::cin.clear();

			std::cin >> currentChar;

			if (currentChar == 'q' || currentChar == 'Q') //logic if user has entered q/Q
			{
				inputting = false;
			}
			else
			{
				std::cin.clear();
				std::cin.ignore(std::cin.rdbuf()->in_avail());
				std::cout << "Your input was invalid, please try again" << std::endl;
				continue;
			}
		}
		else
		{
			runningTotal;
		}
	}
}