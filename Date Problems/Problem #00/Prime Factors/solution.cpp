#include <vector>

std::vector<int> prime_factors(long n)
{
    std::vector<int> factors;

    // Check for divisibility by 2
    while (n % 2 == 0)
    {
        factors.push_back(2);
        n /= 2;
    }

    // Check for divisibility by odd numbers starting from 3
    for (int i = 3; i * i <= n; i += 2)
    {
        while (n % i == 0)
        {
            factors.push_back(i);
            n /= i;
        }
    }

    // If n is still greater than 2, it must be a prime number itself
    if (n > 2)
        factors.push_back(n);

    return factors;
}

// .......................................................

#include <vector>
std::vector<int> prime_factors(long n)
{
    std::vector<int> res;
    for (auto i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            res.push_back(i);
            n /= i;
        }
    }
    if (n > 1)
        res.push_back(n);
    return res;
}