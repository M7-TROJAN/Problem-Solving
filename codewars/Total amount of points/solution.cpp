#include <array>
#include <string>
int points(const std::array<std::string, 10> &games)
{
    int result = 0;
    for(const std::string &game : games)
    {
        if(std::to_string(game[0]) > std::to_string(game[2])) result+=3;
        if(std::to_string(game[0]) == std::to_string(game[2])) result+=1;
    }
    return result;
}
