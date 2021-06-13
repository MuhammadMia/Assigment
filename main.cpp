#include <iostream>
#include <stdlib.h>
#include <fstream>

#include <mcq.h>
#include <tfq.h>

using namespace std;

enum ans
{
    A = 0, //* Answer 1
    B = 1, //* Unsure
    C = 2  //* Answer 2
};

int main(int argc, char const *argv[])
{
    fstream questionFile;
    questionFile.open("questions.txt", ios::in);

    if (!questionFile)
    {
        cout << "File not found!";
        exit(1);
    }

    questionFile.close();

    mcq q = {"Are you gay?", "Yes", "No", 4};

    q.answer = static_cast<ans>(askMCQ(q));

    return 0;
}