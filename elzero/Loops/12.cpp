#include <iostream>
#include <algorithm>
#include <array>
#include <cstring>
using namespace std;
int main()
{
  int nums[] = {10, 20, 14, 28, 40, 80, 15, 30};
  
  // إذا كان الرقم الحالي + نفسه يساوي الرقم الذي بعده قم بطباعته اما غير ذلك لا تطبعه

  int n = sizeof(nums) / sizeof(nums[0]);
  for(int i = 0 ; i < n; i++)
  {
    if( (nums[i] + nums[i]) == nums[i+1])
      cout << nums[i] << endl;
  }
}

// Output Needed
/* 
10
14
40
15 
*/