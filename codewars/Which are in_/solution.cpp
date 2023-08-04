#include <iostream>
#include <vector>
#include <algorithm>

class WhichAreIn {
public:
    static std::vector<std::string> inArray(std::vector<std::string>& array1, std::vector<std::string>& array2) {
        std::vector<std::string> result;

        for (const std::string& str1 : array1) {
            for (const std::string& str2 : array2) {
                if (str2.find(str1) != std::string::npos) {
                    result.push_back(str1);
                    break;
                }
            }
        }

        std::sort(result.begin(), result.end());

        return result;
    }
};


// ........................................................................

#include <vector>
#include <string>
using namespace std;
vector<string> inArray(const vector<string>& array1, const vector<string>& array2) {
    vector<string> result; // Store the common strings found

    // Iterate over each string in array1
    for (const string& str1 : array1) {
        // Iterate over each string in array2
        for (const string& str2 : array2) {
            // Check if str1 is a substring of str2
            if (str2.find(str1) != string::npos) {
                result.push_back(str1); // Add str1 to the result vector
                break; // Exit the inner loop once a common string is found
            }
        }
    }
    return result; // Return the vector containing the common strings
}
