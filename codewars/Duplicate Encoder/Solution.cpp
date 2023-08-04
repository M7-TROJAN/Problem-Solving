#include <iostream>
#include <unordered_map>
#include <string>

std::string duplicate_encoder(const std::string& str) {
    std::unordered_map<char, int> charCount;

    // Count the frequency of each character
    for (char c : str) {
        char lowercase = std::tolower(c);  // Ignore capitalization
        charCount[lowercase]++;
    }

    std::string result;

    // Construct the new string based on character frequency
    for (char c : str) {
        char lowercase = std::tolower(c);  // Ignore capitalization

        // Append "(" if the character appears only once, or ")" otherwise
        if (charCount[lowercase] > 1) {
            result += ")";
        } else {
            result += "(";
        }
    }

    return result;
}

int main() {
    std::cout << duplicate_encoder("din") << std::endl;         // Output: (((
    std::cout << duplicate_encoder("recede") << std::endl;      // Output: ()()()
    std::cout << duplicate_encoder("Success") << std::endl;     // Output: )())())
    std::cout << duplicate_encoder("(( @") << std::endl;        // Output: ))((
    
    return 0;
}
