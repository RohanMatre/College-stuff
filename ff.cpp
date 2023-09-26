#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> productions;
int fvar;

int findPos(char NonTer)
{
    int i = 0;
    while (productions[i][0] != NonTer)
        i++;
    return i;
}

string findGenerating(char Ter)
{
    int i = 0;
    while (productions[i][0] != Ter)
        i++;
    return productions[i];
}

void findFirst(const string &prod)
{
    int i, j = 0;
    for (i = 3; i < prod.length(); i++)
    {
        if ((prod[i] >= 'a' && prod[i] <= 'z') || prod[i] == ')' || prod[i] == '(' || prod[i] == ',')
        {
            cout << " " << prod[i] << " ";

            while (prod[i] != '/' && i < prod.length())
                i++;
        }
        else if (prod[i] >= 'A' && prod[i] <= 'Z')
        {
            string ans = findGenerating(prod[i]);
            findFirst(ans);
            return;
        }
        else if (prod[i] == '#')
        {
            cout << " # ";
        }
        else
            continue;
    }
}

void findFollow(char GeneratingSymbol, int n)
{
    int i, j = 0;
    if (GeneratingSymbol == 'S')
        cout << " $ ";
    for (j = 0; j < n; j++)
    {
        for (i = 3; i < productions[j].length(); i++)
        {
            if (GeneratingSymbol == productions[j][i])
            {
                if ((productions[j][i + 1] >= 'a' && productions[j][i + 1] <= 'z') || productions[j][i + 1] == ')' || productions[j][i + 1] == '(' || productions[j][i + 1] == ',')
                {
                    cout << " " << productions[j][i + 1] << " ";
                }
                else if (productions[j][i + 1] >= 'A' && productions[j][i + 1] <= 'Z')
                {
                    string ans = findGenerating(productions[j][i + 1]);
                    findFirst(ans);
                }
                else if (i + 1 == productions[j].length())
                {
                    findFollow(productions[j][0], n);
                }
                else
                    continue;
            }
        }
    }
}

int main()
{
    int j, i, n, k, tempInd, flag = 0;
    cout << "Enter the number of productions: ";
    cin >> n;
    productions.resize(n);

    vector<string> productionsDup(n);

    cin.ignore(); // Consume the newline character after reading 'n'

    for (i = 0; i < n; i++)
    {
        getline(cin, productions[i]);
        productionsDup[i] = productions[i];
    }

    // First Computation
    for (i = 0; i < n; i++)
    {
        cout << "\nFIRST(" << productions[i][0] << ")={  ";
        findFirst(productions[i]);
        cout << "}\n";
    }

    for (fvar = 0; fvar < n; fvar++)
    {
        cout << "\nFOLLOW(" << productions[fvar][0] << ")={";
        findFollow(productions[fvar][0], n);
        cout << "}\n";
    }

    cout << "\nThe End" << std::endl;
}
