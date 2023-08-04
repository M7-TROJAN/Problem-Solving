int opposite(int number)
{
    return number * -1;
}

//..................................

int opposite(const int &number)
{
    return -number;
}