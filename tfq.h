#include <iostream>
#include <stdlib.h>

using namespace std;

struct tfq
{
    string question;
    int number;
    bool answer;
};

bool askTFQ(tfq q)
{
    bool userAnswer;
    char userResponse;

    system("CLS"); //* Clears the screen
    cout << "~~ Section A ~~ "
         << "\t\t\t\t\tQuestion "
         << q.number
         << " / 9"; //* Header bar
    cout << "\t(";

    for (int i = 0; i < q.number; i++)
    {
        cout << "=";
    }

    for (int i = 0; i < 9 - q.number; i++)
    {
        cout << "-";
    }

    cout << ")";
    cout << "\n\n"
         << q.question << "\n"; //* Question
    cout << "\n A: True";       //* True
    cout << "\n B: False";      //* False
    cout << "\n\nYour answer: ";
    cin >> userResponse;

    switch (userResponse)
    {
    case 'A':
    case 'a':
        cout << "Your answer: True";
        userAnswer = true;
        break;

    case 'B':
    case 'b':
        cout << "Your answer: False";
        userAnswer = false;
        break;
    }

    cout << "\n\n~~ Press enter to continue ~~";
    cin.ignore();

    return (userAnswer);
}
