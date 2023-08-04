#include <iostream>

double power(double base, double exponent)
{
    double result = 1.0;
    for (int i = 0; i < exponent; i++)
    {
        result *= base;
    }
    return result;
}

int main()
{
    double base, exponent;
    std::cout << "Enter base: ";
    std::cin >> base;
    std::cout << "Enter exponent: ";
    std::cin >> exponent;
    std::cout << base << " raised to the power of " << exponent << " is " << power(base, exponent) << std::endl;
    return 0;
}
