#include <iostream>
int main()
{
    // Bitwise ANd
    std::cout << "The Result Of (12 & 25 )  Is: " << (12 & 25 )  << std::endl;
    std::cout << "The Result Of (10 & 30 )  Is: " << (10 & 30 )  << std::endl;
    std::cout << "The Result Of (17 & 100)  Is: " << (17 & 100)  << std::endl;
    std::cout << "The Result Of (54 & 87 )  Is: " << (54 & 87 )  << std::endl;
    std::cout << "The Result Of (2  &  19)  Is: " << ( 2 & 19 )  << std::endl;

    std::cout << "================================\n";

    // Bitwise OR
    std::cout << "The Result Of (12 | 25 )  Is: " << (12 | 25 )  << std::endl;
    std::cout << "The Result Of (10 | 30 )  Is: " << (10 | 30 )  << std::endl;
    std::cout << "The Result Of (17 | 100)  Is: " << (17 | 100)  << std::endl;
    std::cout << "The Result Of (54 | 87 )  Is: " << (54 | 87 )  << std::endl;
    std::cout << "The Result Of (2  |  19)  Is: " << ( 2 | 19 )  << std::endl;

    std::cout << "================================\n";

    // Bitwise XOR
    std::cout << "The Result Of (12 ^ 25 )  Is: " << (12 ^ 25 )  << std::endl;
    std::cout << "The Result Of (10 ^ 30 )  Is: " << (10 ^ 30 )  << std::endl;
    std::cout << "The Result Of (17 ^ 100)  Is: " << (17 ^ 100)  << std::endl;
    std::cout << "The Result Of (54 ^ 87 )  Is: " << (54 ^ 87 )  << std::endl;
    std::cout << "The Result Of (2  ^  19)  Is: " << ( 2 ^ 19 )  << std::endl;
    system("PAUSE");
}