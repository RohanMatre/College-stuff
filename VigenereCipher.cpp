#include <iostream>
#include <string>
using namespace std;

string encrypt(string plaintext, string key)
{
    string ciphertext = "";
    int keyLength = key.length();

    for (int i = 0; i < plaintext.length(); i++)
    {
        char plainChar = plaintext[i];
        char keyChar = key[i % keyLength];

        if (isalpha(plainChar))
        {
            int shift = keyChar - 'A';
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
    int keyLength = key.length();

    for (int i = 0; i < ciphertext.length(); i++)
    {
        char cipherChar = ciphertext[i];
        char keyChar = key[i % keyLength];

        if (isalpha(cipherChar))
        {
            int shift = keyChar - 'A';
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
