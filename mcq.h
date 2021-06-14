#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>

using namespace std;

enum ans
{
    A = 0, //* Answer 1
    B = 1, //* Unsure
    C = 2  //* Answer 2
};

struct mcq
{
    string question;
    string option1;
    string option2;
    int number;
    ans answer;
};

char askMCQ(mcq q)
{
    char userAnswer;

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
         << q.question << "\n";    //* Question
    cout << "\n A: " << q.option1; //* Option A
    cout << "\n B: Unsure";        //* Option B
    cout << "\n C: " << q.option2; //* Option C
    cout << "\n\nYour answer: ";
    cin >> userAnswer;

    switch (userAnswer)
    {
    case 'A':
    case 'a':
        cout << "Your answer: " << q.option1;
        break;

    case 'B':
    case 'b':
        cout << "Your answer: Unsure";
        break;

    case 'C':
    case 'c':
        cout << "Your answer: " << q.option2;
        break;
    }

    cout << "\n\n~~ Press enter to continue ~~";
    cin.ignore();

    return (userAnswer);
}

//* Function below takes in a filename and returns a pointer to an array of questions
mcq *readMCQ(string filename)
{
    fstream questionFile;
    questionFile.open(filename, ios::in);

    if (!questionFile) //* Making sure the file is found
    {
        cout << "File not found!";
        exit(1);
    }
    else
    {
        cout << "\nFile found, continuing...";
    }

    mcq questions[15];
    int qCount = 0;

    string temp;
    string question[3];
    int i = 0;

    if (questionFile.is_open())
    {

        while (getline(questionFile, temp))
        {
            cout << "\n"
                 << temp;
            if (!(temp == "-----"))
            {
                questions[qCount] = {question[0], question[1], question[2], qCount + 1};
                i = 0;
                qCount++;
            }
            else
            {
                question[i] = temp;
                i++;
            }
        }
    }

    questionFile.close();

    mcq *qp;
    qp = questions;

    return qp;
}