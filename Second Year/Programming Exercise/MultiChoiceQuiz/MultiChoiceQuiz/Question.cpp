#include "Question.h"
#include <iostream>

Question::Question(const char* question, Answer a, Answer b, Answer c)
{
	questionChar = question;

	answerA = a;
	answerB = b;
	answerC = c;
}

void Question::DisplayQuestion()
{
	std::cout << questionChar << "?" << std::endl;
	std::cout << answerA.GetAnswer() << std::endl;
	std::cout << answerB.GetAnswer() << std::endl;
	std::cout << answerC.GetAnswer() << std::endl;
}

bool Question::CheckAnswer(char a)
{
	if ((a == 'A' && answerA.IsCorrect()) ||
		(a == 'B' && answerB.IsCorrect()) ||
		(a == 'C' && answerC.IsCorrect()))
	{
		std::cout << "Correct!" << std::endl;
		return true;
	}
	else
	{
		std::cout << "Wrong!" << std::endl;
		return false;
	}
}
