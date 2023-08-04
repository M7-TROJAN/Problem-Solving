/*
    Write a program to read a text and encrypt it, decrypt it.

    Input:
    Mohammed

    Output:
    Text Before Encryption : Mohammed
    Text After Encryption  : Oqjcoogf
    Text After Decryption  : Mohammed
*/

#include <iostream>
#include <string>
using namespace std;

// This function reads the text input from the user and returns it as a string.
string ReadText()
{
    string Text;
    cout << "Enter Text:\n";
    getline(cin, Text);
    return Text;
}

// This function takes a string and an encryption key and returns the encrypted string.
string EncryptText(string Text, short EncryptionKey)
{
    // Iterate over each character in the string and add the encryption key to its ASCII code.
    for (int i = 0; i < Text.length(); i++)
    {
        Text[i] = char((int)Text[i] + EncryptionKey);
    }
    return Text;
}

// This function takes a string and an encryption key and returns the decrypted string.
string DecryptText(string Text, short EncryptionKey)
{
    // Iterate over each character in the string and subtract the encryption key from its ASCII code.
    for (int i = 0; i < Text.length(); i++)
    {
        Text[i] = char((int)Text[i] - EncryptionKey);
    }
    return Text;
}

int main()
{   
    // This is the encryption key.
    const short EncryptionKey = 9; 

    string TextAfterEncryption, TextAfterDecryption;

    string Text = ReadText();

    // Encrypt the text using the encryption key.
    TextAfterEncryption = EncryptText(Text, EncryptionKey);

    // Decrypt the text using the encryption key.
    TextAfterDecryption = DecryptText(TextAfterEncryption, EncryptionKey);

    // Print the original text, encrypted text, and decrypted text to the console.
    cout << "================================\n";
    cout << "Text Before Encryption : ";
    cout << Text << endl;
    cout << "Text After Encryption  : ";
    cout << TextAfterEncryption << endl;
    cout << "Text After Decryption  : ";
    cout << TextAfterDecryption << endl;

    return 0;
}
