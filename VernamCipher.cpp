#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

string generateRandomKey(int length)
{
    string key = "";
    srand(time(0));

    for (int i = 0; i < length; i++)
    {
        char randomChar = 'A' + (rand() % 26); // Generating random uppercase letters
        key += randomChar;
    }

    return key;
}

string encrypt(string plaintext, string key)
{
    string ciphertext = "";

    for (int i = 0; i < plaintext.length(); i++)
    {
        char plainChar = plaintext[i];
        char keyChar = key[i];

        if (isalpha(plainChar))
        {
            int shift = (toupper(keyChar) - 'A');
            if (islower(plainChar))
            {
                ciphertext += (plainChar - 'a' + shift) % 26 + 'a';
            }
            else
            {
                ciphertext += (plainChar - 'A' + shift) % 26 + 'A';
            }
        }
        else
        {
            ciphertext += plainChar;
        }
    }

    return ciphertext;
}

string decrypt(string ciphertext, string key)
{
    string plaintext = "";

    for (int i = 0; i < ciphertext.length(); i++)
    {
        char cipherChar = ciphertext[i];
        char keyChar = key[i];

        if (isalpha(cipherChar))
        {
            int shift = (toupper(keyChar) - 'A');
            if (islower(cipherChar))
            {
                plaintext += (cipherChar - 'a' - shift + 26) % 26 + 'a';
            }
            else
            {
                plaintext += (cipherChar - 'A' - shift + 26) % 26 + 'A';
            }
        }
        else
        {
            plaintext += cipherChar;
        }
    }

    return plaintext;
}

int main()
{
    string plaintext;
    int length;

    cout << "Enter the Plain text: ";
    getline(cin, plaintext);

    length = plaintext.length();
    string key = generateRandomKey(length);

    cout << "Generated Key: " << key << endl;

    string encrypted = encrypt(plaintext, key);
    cout << "Cipher text: " << encrypted << endl;

    string decrypted = decrypt(encrypted, key);
    cout << "Decryption text: " << decrypted << endl;

    return 0;
}
