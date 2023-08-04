bool isDivisible(int n, int x, int y)
{
    if (n % x == 0 && n % y == 0)
        return true;
    return false;
}