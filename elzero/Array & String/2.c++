#include <iostream>
using namespace std;


int main()
{
  // Example 1
  int check1 = 25;
  int nums1[]{40, 20, 30, 70, 100};

  // Ouput Needed
  // "{40} + {70} = 110"

  int n = sizeof(nums1) / sizeof(nums1[0]);
  for (int i = 0; i < n; i++)
  {
    if (check1 < nums1[i])
    {
      cout << "{" << nums1[i] << "} + {" << nums1[n - 2] << "} = " << nums1[i] + nums1[n - 2] << endl;
      break;
    }
  }

  //..............................................................................................

  // Example 2
  int check2 = 25;
  int nums2[]{20, 35, 30, 70, 100};

  // Ouput
  // "{35} + {70} = 105"

  n = sizeof(nums2) / sizeof(nums2[0]);
  for (int i = 0; i < n; i++)
  {
    if (nums2[i] > check2)
    {
      cout << "{" << nums2[i] << "} + {" << nums2[n - 2] << "} = " << nums2[i] + nums2[n - 2] << endl;
      break;
    }
  }

  //..............................................................................................

  // Example 2
  int check3 = 25;
  int nums3[]{20, 25, 30, 70, 100};

  // Ouput
  // "{30} + {70} = 100"

  n = sizeof(nums3) / sizeof(nums3[0]);
  for (int i = 0; i < n; i++)
  {
    if (check3 < nums3[i])
    {
      cout << "{" << nums3[i] << "} + {" << nums3[n - 2] << "} = " << nums3[i] + nums3[n - 2] << endl;
      break;
    }
  }
}