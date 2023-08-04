int odd_count(int n)
{
    // if n = even: odd numbers below n is n/2
    // if n = odd: odd numbers below n is n/2 rounded down, which C++ will do for us
    return n / 2;
}