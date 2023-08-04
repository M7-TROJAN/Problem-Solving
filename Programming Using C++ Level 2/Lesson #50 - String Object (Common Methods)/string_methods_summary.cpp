
// In C++, the string object provides various methods to manipulate and access strings. Here are some examples of commonly used methods:

#include <iostream>
#include <string>
#include <algorithm>
int main()
{
    // 1- length:
    std::string str = "Hello, World!";
    int length = str.length(); // returns the length of the string (12)

    // 2- Accessing individual characters:
    std::string str = "Hello";
    char firstChar = str[0]; // accessing the first character ('H')

    // 3- Concatenation:
    std::string str1 = "Hello";
    std::string str2 = " World!";
    std::string result = str1 + str2; // concatenates the two strings ("Hello World!")

    // 4- Substring:
    std::string str = "Hello, World!";
    std::string substring = str.substr(7, 5); // extracts a substring starting from index 7 with length 5 ("World")

    // 5- Searching for a substring:
    std::string str = "Hello, World!";
    size_t found = str.find("World"); // finds the index of the first occurrence of "World" (7)

    // 6- Case conversion:
    std::string str = "Hello, World!";
    std::transform(str.begin(), str.end(), str.begin(), ::tolower); // converts the string to lowercase ("hello, world!")

    // 7- Comparison:
    std::string str1 = "Hello";
    std::string str2 = "World";
    int result = str1.compare(str2); // compares the two strings (-1 indicates str1 is lexicographically less than str2)

    // 8- Replacing a substring:
    std::string str = "Hello, World!";
    str.replace(7, 5, "Everyone"); // replaces the substring "World" with "Everyone" ("Hello, Everyone!")

    // 9- Removing leading and trailing whitespace:
    std::string str = "   Hello, World!   ";
    str = str.erase(0, str.find_first_not_of(' ')); // removes leading whitespace
    str = str.erase(str.find_last_not_of(' ') + 1); // removes trailing whitespace ("Hello, World!")

    std::string str5 = "mahmoud";
    if (str5.find("oud") == str5.npos)    // npos means => No Position i.e Not Found
    {
        std::cout << "ali is not found";
    }
    else 
        std::cout<< str5.find("oud") << "\n";
}