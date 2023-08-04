#include <string>

int solve(const std::string& s) {
    int highestValue = 0;
    int currentValue = 0;

    for (char c : s)
    {
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u') 
        {
            currentValue += c - 'a' + 1; // Calculate the value of the consonant

            if (currentValue > highestValue)
            {
                highestValue = currentValue; // Update the highest value if necessary
            }
        }
        else
        {
            currentValue = 0; // Reset the current value when encountering a vowel
        }
    }

    return highestValue;
}