#include <string>

std::string people_with_age_drink(int age)
{
    if (age < 14)
        return "drink toddy";
    if (age < 18)
        return "drink coke";
    if (age < 21)
        return "drink beer";
    return "drink whisky";
}

// .............................................................

// solution with switch
#include <iostream>
#include <string>
std::string people_with_age_drink(int age)
{
    switch (age)
    {
        case 0 ... 13:
            return "drink toddy";

        case 14 ... 17:
            return "drink coke";

        case 18 ... 20:
            return "drink beer";

        case 21 ... 90:
            return "drink whisky";
    }

    return "";
}

// .............................................................

// solution with TerOp

#include <string>

std::string people_with_age_drink(int old) {
    std::string s = "drink " ;
    s += old < 14 ? "toddy" : old < 18 ? "coke" : old < 21 ? "beer" : "whisky";
    return s;  
}
