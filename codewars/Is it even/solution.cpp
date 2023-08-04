
#include <cmath>
bool is_even(double n)
{
    return fmod(n , 2) == 0;
}

// ...........................................................................

// some logic :)
#include <cmath>
bool is_even(double n)
{
    if(ceil(n) != floor(n)) return false;
    return ((int)n)%2 == 0;
}