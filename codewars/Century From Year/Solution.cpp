int ceilNumber(float x)
{
    float fractionalPart = x - int(x);
    if (fractionalPart <= 0)
        return (int)x;
    else
        return (int)x + 1;
}
int centuryFromYear(int year)
{
    float century = year / 100.0;
    return ceilNumber(century);
}