#include <iostream>
#include <string>

// Base case of the recursive function to concatenate strings
std::string concat()
{
    return "";
}

// Recursive function to concatenate strings
template <typename... Args>
std::string concat(const std::string &first, const Args &...args)
{
    return first + concat(args...);
}

int main()
{
    std::string result = concat("Hello, ", "world", "!", "Iam", " Mahmoud", "and ", " This", " is", " a", " concatenated", " string.");
    std::cout << result << std::endl;
    return 0;
}