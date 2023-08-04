#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> numbers = {10, 20, 10, 40, 50, 60, 10, 80};
    int check = 10;
    int countone = 0;
    int counttwo = 0;

    // Method One: Using a loop
    for(auto i = numbers.begin() ; i != numbers.end() ; i++)
    {
        if(*(i) == check )
            countone++;
    }

    // Method Two: Using count algorithm
    counttwo = count(numbers.begin(), numbers.end(), check);

    cout << countone << "\n"; // 3
    cout << counttwo << "\n"; // 3
    return 0;
}