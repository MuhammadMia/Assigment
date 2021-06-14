#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>

using namespace std;

struct mcq
{
    string question;
    string option1;
    string option2;
    int number;
    int answer;
};

int askMCQ(mcq q, int level)
{
    char userAnswer;

    system("CLS"); //* Clears the screen
    cout << "~~ Section " << level << " ~~ "
         << "\t\t\tQuestion "
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
        cout << "\n\n~~ Press enter to continue ~~";
        cin.ignore();

        return (0);
        break;

    case 'B':
    case 'b':
        cout << "Your answer: Unsure";
        cout << "\n\n~~ Press enter to continue ~~";
        cin.ignore();

        return (1);
        break;

    case 'C':
    case 'c':
        cout << "Your answer: " << q.option2;
        cout << "\n\n~~ Press enter to continue ~~";
        cin.ignore();

        return (2);
        break;
    }
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
        cout << "\nSuccess! File found, continuing...";
    }

    static mcq questions[16];
    int qCount = 0;

    string temp;
    string question[3];
    int i = 0;

    if (questionFile.is_open())
    {
        while (getline(questionFile, temp))
        {
            if (temp == "-----")
            {
                questions[qCount] = {question[0], question[1], question[2], qCount};
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

bool totalMCQ(mcq *p)
{
    int totalA = 0;
    int totalC = 0;

    for (int i = 1; i < 10; i++)
    {
        if ((p + i)->answer == 0)
        {
            totalA++;
        }
        if ((p + i)->answer == 1)
        {
            //* Records nothing
        }
        if ((p + i)->answer == 2)
        {
            totalC++;
        }
    }

    if (totalA >= totalC)
    {
        return true;
    }
    else
    {
        return false;
    }
}