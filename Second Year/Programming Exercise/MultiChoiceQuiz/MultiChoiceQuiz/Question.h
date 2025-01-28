#pragma once
#include "Answer.h"

class Question
{
public: //functions

	Question(const char* question, Answer a, Answer b, Answer c);

	void DisplayQuestion();

	bool CheckAnswer(char a);

public: //variables

	const char* questionChar;

	Answer answerA;
	Answer answerB;
	Answer answerC;
};