#include <iostream>
#include <string>
#include <random>
#include <chrono>
using namespace std;

enum class CharType { SmallLetter, CapitalLetter, SpecialCharacter, Digit };

// Generates a random integer between two given values (inclusive)
int RandomNumber(int from, int to) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(from, to);
    return dis(gen);
}

// Generates a random character of the specified type
char GetRandomCharacter(CharType type) {
    string charSet;
    switch (type) {
        case CharType::SmallLetter:
            charSet = "abcdefghijklmnopqrstuvwxyz";
            break;
        case CharType::CapitalLetter:
            charSet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
            break;
        case CharType::SpecialCharacter:
            charSet = "!@#$%^&*()_+-={}[]|\\:;\"',.?/";
            break;
        case CharType::Digit:
            charSet = "0123456789";
            break;
        default:
            throw invalid_argument("Invalid character type.");
    }
    int charIndex = RandomNumber(0, charSet.length() - 1);
    return charSet[charIndex];
}

// Generates a random password of the specified length
string GeneratePassword(int length) 
{
    string password;
    password.reserve(length);
    for (int i = 0; i < length; ++i) {
        CharType type = static_cast<CharType>(RandomNumber(0, 3));
        password += GetRandomCharacter(type);
    }
    return password;
}

int main() {
    random_device rd;
    mt19937 gen(rd());
    gen.seed(chrono::system_clock::now().time_since_epoch().count());

    string password = GeneratePassword(12);
    cout << "Generated password: " << password << endl;

    system("PAUSE");

    return 0;
}
