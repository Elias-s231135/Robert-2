// MultiChoiceQuiz.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "Question.h"
#include "Answer.h"

int main()
{
    int score = 0;

    std::vector<Question> questions;
    Question q1("What is mince", Answer("A: Food", true), Answer("B: Furniture", false), Answer("C: Vehicle", false));
    Question q2("What colour is mince", Answer("A: Purple", false), Answer("B: Blue", false), Answer("C: Red", true));
    Question q3("What pattern is mince", Answer("A: Zig-zag", false), Answer("B: Wavy", true), Answer("C: Polka-dot", false));
    Question q4("What is mince made of", Answer("A: Wood", false), Answer("B: Beef", true), Answer("C: Bees", false));
    Question q5("How inevitable is mince", Answer("A: Very", true), Answer("B: A little", false), Answer("C: Not at all", false));
    questions.push_back(q1);
    questions.push_back(q2);
    questions.push_back(q3);
    questions.push_back(q4);
    questions.push_back(q5);

    std::cout << "Welcome to the mince quiz! Are you ready to get mincy? " << std::endl;
    std::cout << "Y/N" << std::endl;
    char yn;
    std::cin >> yn;
    if (yn == 'N')
    {
        return 0;
    }
    else if (yn == 'Y')
    {
        // ask questions
        for (auto q = questions.begin(); q != questions.end(); q++)
        {
            /*clear screen?*/
            q->DisplayQuestion();
            char a;
            std::cin >> a;
            q->CheckAnswer(a);
            if (q->CheckAnswer(a) == true)
            {
                score++;
            }
        }
    }
    else
    {
        std::cout << "Didn't get that, try again." << std::endl;
        std::cin >> yn;
    }

    std::cout << "Great work! you got " << score << "/5 correct!" << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
