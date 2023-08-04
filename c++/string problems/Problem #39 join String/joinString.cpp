#include <iostream>
#include <vector>

// This function joins a vector of strings into a single string using a delimiter
std::string joinString(const std::vector<std::string> &vString, const std::string &delimiter = " ")
{
    std::string result = "";
    for (int i = 0; i < vString.size(); i++)
    {
        result += vString.at(i);
        if (i != vString.size() - 1)
            result += delimiter;
    }
    return result;
}

int main()
{
    std::vector<std::string> names = {"Mahmoud", "Mohamed", "Abdalaziz", "Ali", "Adam"};

    std::string joinedNames = joinString(names, ", ");

    std::cout << "Joined names: " << joinedNames << std::endl;

    return 0;
}
