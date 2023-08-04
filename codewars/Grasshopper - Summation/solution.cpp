// basic solution
int summation(int num)
{
    int result = 0;
    for(int i = 1; i <= num; i++)
    {
        result+= i;
    }
    return result;
}

// .................................................

// cool solution
int summation(int num)
{
    return num * (num + 1) / 2;  // using some of logic :)
}

/*
    Note:
    ' num * (num + 1) / 2 ' calculates the summation of numbers from 1 to the given num
    using a mathematical formula known as 'the arithmetic series formula.' search about it or look at the Links below
    https://www.alamo.edu/contentassets/afe30946fa58450c89840c1173f3b9d0/sequences/math1314-arithmetic-sequences.pdf
    https://byjus.com/maths/sum-of-n-terms/
*/
