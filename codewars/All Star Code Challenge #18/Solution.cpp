#include <string>

unsigned int strCount(const std::string& word, char letter){
    short result = 0;
    for (auto &&c : word)
    {
        if(c == letter)
            result++;
    }
    return result;

    // another way by using built in fun
    return std::count(word.cbegin(), word.cend(), letter); // you Should Include <algorithm> header file to use count();

}