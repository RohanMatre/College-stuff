#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string encrypt(string plaintext, string key)
{
    int keyLength = key.length();
    vector<int> order(keyLength);

    for (int i = 0; i < keyLength; i++)
    {
        order[i] = i;
    }

    // Sort the order array based on the key
    sort(order.begin(), order.end(), [&key](int a, int b) { return key[a] < key[b]; });

    int numRows = (plaintext.length() + keyLength - 1) / keyLength;
    vector<vector<char>> grid(numRows, vector<char>(keyLength, ' '));

    for (int i = 0; i < plaintext.length(); i++)
    {
        grid[i / keyLength][i % keyLength] = plaintext[i];
    }

    string ciphertext = "";
    for (int col : order)
    {
        for (int row = 0; row < numRows; row++)
        {
            if (grid[row][col] != ' ')
            {
                ciphertext += grid[row][col];
            }
        }
    }

    return ciphertext;
}

string decrypt(string ciphertext, string key)
{
    int keyLength = key.length();
    vector<int> order(keyLength);

    for (int i = 0; i < keyLength; i++)
    {
        order[i] = i;
    }

    // Sort the order array based on the key
    sort(order.begin(), order.end(), [&key](int a, int b) { return key[a] < key[b]; });

    int numRows = (ciphertext.length() + keyLength - 1) / keyLength;
    int numCols = keyLength;
    vector<vector<char>> grid(numRows, vector<char>(numCols, ' '));

    int index = 0;
    for (int col : order)
    {
        for (int row = 0; row < numRows; row++)
        {
            if (index < ciphertext.length())
            {
                grid[row][col] = ciphertext[index];
                index++;
            }
        }
    }

    string plaintext = "";
    for (int row = 0; row < numRows; row++)
    {
        for (int col = 0; col < numCols; col++)
        {
            if (grid[row][col] != ' ')
            {
                plaintext += grid[row][col];
            }
        }
    }

    return plaintext;
}

int main()
{
    string plaintext, key;

    cout << "Enter the Plain text: ";
    getline(cin, plaintext);

    cout << "Enter the Key: ";
    cin >> key;

    string encrypted = encrypt(plaintext, key);
    cout << "Cipher text: " << encrypted << endl;

    string decrypted = decrypt(encrypted, key);
    cout << "Decryption text: " << decrypted << endl;

    return 0;
}
