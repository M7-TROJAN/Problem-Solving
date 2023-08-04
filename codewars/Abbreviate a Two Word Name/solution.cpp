#include <string>

std::string abbrevName(std::string name)
{
    std::string newName = "";
    newName += toupper(name[0]);
    newName += '.';
    newName += toupper(name[name.find(' ') +1]);
    return newName;
}