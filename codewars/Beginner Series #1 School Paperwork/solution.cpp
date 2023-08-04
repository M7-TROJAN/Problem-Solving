int paperwork(int n, int m)
{
    return (n <=0 || m <= 0)? 0 : m *n;
}

// ........................................................

#include <algorithm>

int paperwork(int n, int m)
{
    return std::max(n, 0) * std::max(m, 0);
}