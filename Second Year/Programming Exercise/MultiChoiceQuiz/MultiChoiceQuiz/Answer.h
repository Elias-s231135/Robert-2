#pragma once
class Answer
{
public:

	Answer() { answerChar = ""; isCorrect = false; }

	Answer(const char* answer, bool truth = false);
	bool IsCorrect() { return isCorrect; }
	const char* GetAnswer() { return answerChar; }

private:

	const char* answerChar;
	bool isCorrect;
};

