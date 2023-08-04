#include <string>
#include <cctype>
#include <map>

std::string duplicate_encoder(const std::string& word){

    std::map<char, int> table;
    for(auto x : word) table[std::tolower(x)]++;
    
    std::string result;
    for(auto x: word) result += (table[std::tolower(x)]==1)? "(" : ")";
    
    return result;
}