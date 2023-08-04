#include <string>
std::string greet(std::string name)
{
    if (name == "Johnny")
    {
        return "Hello, my love!";
    }
    return "Hello, " + name + "!";
}

// jenny is very stupid :(

// return "Hello, " + ( name == "Johnny" ? "my love" : name) + "!";
