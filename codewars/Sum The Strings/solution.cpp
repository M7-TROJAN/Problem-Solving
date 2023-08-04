#include <string>

std::string sum_str(const std::string& a, const std::string& b) {
    int num1 = 0, num2 = 0;
    if(!a.empty())
        num1 = atoi(a.c_str());
    if(!b.empty())
        num2 = atoi(b.c_str());
    return std::to_string(num1 + num2);
}
