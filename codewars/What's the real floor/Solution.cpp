int getRealFloor(int f)
{
    // using ternary op
    return f <= 0 ? f :( f < 13 ? f - 1: f - 2);

    // using if condition
    if (f <= 0)
        return f;
    if (f > 0 && f <= 13)
        return f - 1;
    if (f > 0 && f > 13)
        return f - 2;
}