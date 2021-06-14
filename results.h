#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>

using namespace std;

string getFinalResult(bool totalL1, bool totalL2, bool totalL3, bool totalL4)
{
    //* Compounding into a 4 bit int
    //* A 1 represents true in the specific level, 0 represents false
    string finalResult = "";

    if (totalL1)
    {
        finalResult += "1";
    }
    else
    {
        finalResult += "0";
    }

    if (totalL2)
    {
        finalResult += "1";
    }
    else
    {
        finalResult += "0";
    }

    if (totalL3)
    {
        finalResult += "1";
    }
    else
    {
        finalResult += "0";
    }

    if (totalL4)
    {
        finalResult += "1";
    }
    else
    {
        finalResult += "0";
    }

    return finalResult;
}

void displayFinalResult(string result)
{
    string filename = "results/" + result + ".txt";

    fstream resultFile;
    resultFile.open(filename, ios::in);

    if (!resultFile) //* Making sure the file is found
    {
        cout << "File not found!";
        exit(1);
    }

    static string results[7];
    string temp;
    int count = 0;

    //* Reading the result from the text file
    if (resultFile.is_open())
    {
        while (getline(resultFile, temp))
        {
            results[count] = temp;
            count++;
        }
    }

    //* Displaying
    cout << results[0] << "\n"
         << results[1] << "\n"
         << results[2] << "\n"
         << results[3] << "\n"
         << results[4] << "\n"
         << results[5] << "\n"
         << results[6];
}