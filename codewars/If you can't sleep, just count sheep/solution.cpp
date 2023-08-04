#include <string>
using namespace std;
string countSheep(int number)
{
    string result = "";
    for (int i = 1; i <= number; i++)
        result += to_string(i) + " sheep...";
    return result;
}


// another solution
#include <string>
std::string countSheep(int number)
{
    return number ? countSheep(number - 1) + std::to_string(number) + " sheep..." : "";
}