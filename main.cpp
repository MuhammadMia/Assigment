#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>

#include "tfq.h"
#include "mcq.h"

using namespace std;

int main(int argc, char const *argv[])
{
    fstream questionFile;
    questionFile.open("questions.txt", ios::in);

    if (!questionFile) //* Making sure the file is found
    {
        cout << "File not found!";
        exit(1);
    }
    else
    {
        cout << "\nFile found, continuing...";
    }

    if (questionFile.is_open())
    {
        mcq questions[9];
        int qCount = 0;

        string temp;
        string question[3];
        int i = 0;

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

    return 0;
}