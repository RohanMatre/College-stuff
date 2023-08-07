#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string encrypt(string plaintext, const unordered_map<char, char>& substitutionMap)
{
    string ciphertext = "";

    for (char ch : plaintext)
    {
        if (isalpha(ch))
        {
            char encryptedChar = substitutionMap.at(toupper(ch));
            if (islower(ch))
            {
                encryptedChar = tolower(encryptedChar);
            }
            ciphertext += encryptedChar;
        }
        else
        {
            ciphertext += ch;
        }
    }

    return ciphertext;
}

string decrypt(string ciphertext, const unordered_map<char, char>& substitutionMap)
{
    string plaintext = "";

    for (char ch : ciphertext)
    {
        if (isalpha(ch))
        {
            for (const auto& entry : substitutionMap)
            {
                if (entry.second == toupper(ch))
                {
                    plaintext += entry.first;
                    break;
                }
            }
        }
        else
        {
            plaintext += ch;
        }
    }

    return plaintext;
}

int main()
{
    unordered_map<char, char> substitutionMap = {
        {'A', 'Q'}, {'B', 'W'}, {'C', 'E'}, {'D', 'R'}, {'E', 'T'},
        {'F', 'Y'}, {'G', 'U'}, {'H', 'I'}, {'I', 'O'}, {'J', 'P'},
        {'K', 'A'}, {'L', 'S'}, {'M', 'D'}, {'N', 'F'}, {'O', 'G'},
        {'P', 'H'}, {'Q', 'J'}, {'R', 'K'}, {'S', 'L'}, {'T', 'Z'},
        {'U', 'X'}, {'V', 'C'}, {'W', 'V'}, {'X', 'B'}, {'Y', 'N'},
        {'Z', 'M'}
    };

    string plaintext;

    cout << "Enter the Plain text: ";
    getline(cin, plaintext);

    string encrypted = encrypt(plaintext, substitutionMap);
    cout << "Cipher text: " << encrypted << endl;

    string decrypted = decrypt(encrypted, substitutionMap);
    cout << "Decryption text: " << decrypted << endl;

    return 0;
}
