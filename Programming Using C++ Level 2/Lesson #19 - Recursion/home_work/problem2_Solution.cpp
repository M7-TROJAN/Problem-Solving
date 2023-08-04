#include <iostream>
int MyPower(int Base, int Power)
{

    if (Power == 0)
        return 1;
    else
    {
        return Base * MyPower(Base, Power - 1);
    }
}

int main()
{
    std::cout << MyPower(2, 5) << std::endl;
}




/*

2 * power(2,1)
2 * power(2,2)
2 * power(2,3)
2 * power(2,4)
power(2,5)
*/