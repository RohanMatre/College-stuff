#include <iostream>
#include <fstream>
#include <set>
using namespace std;

int main()
{
    ifstream inputFile("design.cpp");

    string arr[8] = {"int", "using", "namespace", "return", "for", "while", "if", "else"};
    string word;
    set<string> uniqueWords;

    while (inputFile >> word)
    {
        for (int i = 0; i < 8; i++)
        {
            if (word == arr[i])
            {
                if (uniqueWords.find(word) == uniqueWords.end())
                {
                    cout << "Keywords are: " << endl;
                    cout << word << endl;
                    uniqueWords.insert(word);
                }
                break;
            }
        }
    }

    inputFile.close();

    return 0;
}
