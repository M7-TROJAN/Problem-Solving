#include <vector>
#include <string>

bool check(const std::vector<std::string> &seq, const std::string &elem)
{
    for(auto itr = seq.begin(); itr != seq.end(); itr++)
    {
        if(*itr == elem)
            return true;
    }
    return false;
}