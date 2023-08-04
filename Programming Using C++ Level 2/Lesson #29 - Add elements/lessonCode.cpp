#include <iostream>
#include <vector>
int main()
{
    std::vector<int> vNumbers;
    vNumbers.push_back(10);
    vNumbers.push_back(20);
    vNumbers.push_back(30);
    vNumbers.push_back(40);
    vNumbers.push_back(50);

    std::cout << "Numbers Vector: \n\n";
    for (int &Number : vNumbers)
    {
        std::cout << Number << std::endl;
    }
    std::cout << std::endl;
    return 0;
}