#include <array>
#include <string>

std::array<std::string, 3> fixTheMeerkat(std::array<std::string, 3> arr)
{
    return {arr[2], arr[1], arr[0]};
}

//..........................................................................

#include <array>
#include <string>
#include <algorithm>

std::array<std::string, 3> fixTheMeerkat(std::array<std::string, 3> arr)
{
    swap(arr[0], arr[2]);
    return arr;
}