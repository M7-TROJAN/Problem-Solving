#include <vector>
#include <cstdint>
#include <cmath>

std::vector<uint64_t> powers_of_two(int n)
{
    std::vector<uint64_t> result;
    for(int i = 0; i <= n; i++)
    {
        result.push_back(pow(2,i));
    }
    return result;
}

/*
Note:
'uint64_t' is a type in C++ that represents an unsigned 64-bit integer.
It is part of the '<cstdint>' header, which provides fixed-width integer types.

The 'uint64_t' type guarantees that it will be exactly 64 bits in size, regardless of the platform or compiler. It is useful when you need to work with large positive integer values and want to ensure a consistent size across different systems.
*/