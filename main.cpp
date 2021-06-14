#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>

#include "tfq.h"
#include "mcq.h"

using namespace std;

int main(int argc, char const *argv[])
{
    // int qNum;
    // cout << "\nEnter Question Number: ";
    // cin >> qNum;

    mcq *p = readMCQ("level1.txt");

    p->answer = static_cast<ans>(askMCQ(*(p + 1)));

    return 0;
}