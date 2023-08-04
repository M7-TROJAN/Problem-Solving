#include <iostream>
// This function joins an array of strings into a single string using a delimiter
std::string joinString(const std::string arr[], const short& arrLength, const std::string& delimiter = " ")
{
    std::string result = "";
    for (int i = 0; i < arrLength; i++)
    {
        result += arr[i];
        if (i != arrLength - 1)
            result += delimiter;
    }
    return result;
}

int main()
{
    std::string names[] = {"Mahmoud", "Mohamed", "Abdalaziz", "Ali", "Adam"};
    short namesLength = sizeof(names) / sizeof(names[0]);

    std::string joinedNames = joinString(names, namesLength, ", ");

    std::cout << "Joined names: " << joinedNames << std::endl;

    return 0;
}
