#include <iostream>
#include <array>
using namespace std;
int main()
{
  int nums[] = {10, 20, 30, 40, 20, 50};
// get the count of array elements

  array < int, sizeof(nums)/sizeof(nums[0])>n;

  // Method 1
  cout << sizeof(nums) / sizeof(nums[0]) << "\n";

  // Method 2
  cout << n.end() - n.begin() <<"\n";

  // Method 3
  cout << n.size()<<"\n";
}