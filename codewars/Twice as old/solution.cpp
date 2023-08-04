int twice_as_old(int dad, int son)
{
    int result = 2 * son - dad;
    return result < 0 ? -result : result;
}

// .........................................................
#include <cstdlib>
int twice_as_old(int dad, int son)
{
    return abs(son * 2 - dad);
}