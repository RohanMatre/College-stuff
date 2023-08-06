#include <iostream>
#include <string>
using namespace std;

bool is_char(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

bool is_num(char c)
{
    return (c >= '0' && c <= '9');
}

int main()
{
    string n;
    cout << "Enter the str: " << endl;
    cin >> n;

    int t;
    cout << "Enter the no. of matrix: " << endl;
    cin >> t;

    int a[t][t];
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < t; j++)
        {
            cin >> a[i][j];
        }
    }

    int currentstate = 0;
    for (int i = 0; i < n.size(); i++)
    {
        char c = n[i];
        bool match_found = false;

        if (is_char(c))
        {
            for (int j = 0; j < t; j++)
            {
                if (c == char(a[i][j]))
                {
                    match_found = true;
                    break;
                }
            }
        }
        else if (is_num(c))
        {
            int numeric_value = c - '0';
            for (int j = 0; j < t; j++)
            {
                if ((numeric_value == a[i][j] || a[i][j] == -1))
                {
                    match_found = true;
                    break;
                }
            }
        }

        if (!match_found)
        {
            currentstate = 1;
            break;
        }
    }

    if (currentstate == 1)
    {
        cout << "Accepted!!!" << endl;
    }
    else
    {
        cout << "Not Accepted!!!" << endl;
    }
    return 0;
}
