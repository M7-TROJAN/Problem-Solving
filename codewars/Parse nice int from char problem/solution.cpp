#include <string>
int get_age(const std::string& she_said) {
    return she_said[0] - '0';
}

// .................................................................

#include <string>
int get_age(const std::string& she_said) {
    return std::stoi(she_said);
}