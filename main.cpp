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

    if (questionFile.is_open())
    {
        string tp;
        while (getline(questionFile, tp))
        {
            cout << "\n"
                 << tp;
        }
    }

    questionFile.close();

    mcq q = {"Are you gay?", "Yes", "No", 4};

    q.answer = static_cast<ans>(askMCQ(q));

    return 0;
}