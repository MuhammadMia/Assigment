#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>

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

//* Function below takes in a filename and returns a pointer to an array of questions
tfq *readTFQ(string filename)
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

    static tfq questions[10];
    int qCount = 0;

    string temp;

    if (questionFile.is_open())
    {
        while (getline(questionFile, temp))
        {
            if (temp == "-----")
            {
                questions[qCount] = {temp, qCount};
                qCount++;
            }
        }
    }

    questionFile.close();

    tfq *qp;
    qp = questions;

    return qp;
}