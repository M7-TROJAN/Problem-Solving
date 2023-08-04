#include <iostream>
#include <algorithm>
#include <array>
#include <cstring>
using namespace std;
int main()
{
  int nums[] = {2, 4, 5, 6, 10};

// Output Needed
/*
"2 + 10 = 12"
"4 + 6 = 10"
"5 + 5 = 10"
"6 + 4 = 10"
"10 + 2 = 12" 
*/

  int n = sizeof(nums) / sizeof(nums[0]);
  for(int i = 0 ; i < n ; i++)
  {
    cout << nums[i] << " + " << nums[(n-i)-1] << " = " << nums[i] + nums[(n-i) - 1] << "\n";
  }
}