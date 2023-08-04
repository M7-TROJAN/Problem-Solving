#include <string>

std::string update_light(std::string current)
{
    return current == "green" ? "yellow" : (current == "yellow" ? "red" : "green");
}

// ..............................................................................

#include <string>
#include <map>
std::string update_light(std::string current)
{
    std::map<std::string, std::string> mp{{"green", "yellow"}, {"yellow", "red"}, {"red", "green"}};
    return mp[current];
}

// .....................................

// cool solution 

#include <string>
#include <stdexcept>

std::string update_light(const std::string& current) {
    if(current == "green") return "yellow";
    if(current == "yellow") return "red";
    if(current == "red") return "green";
    throw std::invalid_argument{ "Only \"green\", \"yellow\" and \"red\" are allowed! :(" };
}