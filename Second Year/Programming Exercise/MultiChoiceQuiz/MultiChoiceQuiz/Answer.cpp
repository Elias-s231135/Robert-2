#include "Answer.h"

using namespace std;

Answer::Answer(const char* answer, bool truth)
{
	answerChar = answer;
	isCorrect = truth;
}
