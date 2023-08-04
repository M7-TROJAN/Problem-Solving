#include <iostream>
#include <array>
using namespace std;
int main()
{
  array<int, 6> nums = {10, 20, 30, 40, 20, 50};

  // print the first and the last elements of rhe array by 3 different methods

  // Method 1
  int n = nums.size();
  cout << "Method 1\n";
  cout << "First: " << nums[0] << "\n";
  cout << "Last: " << nums[n-1] << "\n";

  // Method 2
  cout << "\nMethod 2\n";
  cout << "First: " << nums.front() << "\n";
  cout << "Last: " << nums.back() << "\n";


  // Method 3
  cout << "\nMethod 3\n";
  int *a = nums.begin();
  int *b = nums.end()-1;
  cout << "First: " << *a << "\n";
  cout << "Last: " << *b << "\n";

  // another method without using any variables or pointers
  cout << "\nalso Method 3\n";
  cout << "First: " << *(nums.begin()) << "\n";
  cout << "Last: " << *(nums.end()-1) << "\n";
  return 0;
}