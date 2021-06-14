#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>

#include "tfq.h"
#include "mcq.h"
#include "results.h"

using namespace std;

int main(int argc, char const *argv[])
{
    //* Asking level 1 Q's
    mcq *p1 = readMCQ("level1.txt");

    for (int i = 1; i < 10; i++)
    {
        (p1 + i)->answer = (askMCQ(*(p1 + i), 1));
    }

    bool total1 = totalMCQ(p1);

    //* Asking level 2 Q's
    mcq *p2 = readMCQ("level2.txt");

    for (int i = 1; i < 10; i++)
    {
        (p2 + i)->answer = (askMCQ(*(p2 + i), 2));
    }

    bool total2 = totalMCQ(p2);

    //* Asking level 3 Q's
    mcq *p3 = readMCQ("level3.txt");

    for (int i = 1; i < 10; i++)
    {
        (p3 + i)->answer = (askMCQ(*(p3 + i), 3));
    }

    bool total3 = totalMCQ(p3);

    //* Asking level 4 Q's
    tfq *p4 = readTFQ("level4.txt");

    for (int i = 1; i < 10; i++)
    {
        (p4 + i)->answer = (askTFQ(*(p4 + i), 4));
    }

    bool total4 = totalTFQ(p4);

    string finalResult = "";

    finalResult = getFinalResult(total1, total2, total3, total4);
    system("CLS");

    displayFinalResult(finalResult);

    return 0;
}