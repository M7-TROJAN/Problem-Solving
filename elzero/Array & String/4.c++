#include <iostream>
using namespace std;
int main()
{
    // Example 1
    int vals1[]{100, 200, 250, 400, 200};

    // Needed Output
    /*
    "First Number + Last Number Is Larger Than Middle Number"
    "100 + 200 = 300"
    "300 > 250"
    */
    int n = sizeof(vals1) / sizeof(vals1[0]);
    if ((vals1[0] + vals1[n - 1]) > vals1[(n - 1) / 2])
        cout << "First Number + Last Number Is Larger Than Middle Number\n";

    //.................................................................

    // Example 2
    int vals2[]{100, 200, 500, 400, 200};

    // Needed Output
    /* "Second Number + Before Last Number Is Larger Than Middle Number"
    "200 + 400 = 600"
    "600 > 500" */

    n = sizeof(vals2) / sizeof(vals2[0]);
    if ((vals2[1] + vals1[n - 2]) > vals1[(n - 1) / 2])
        cout << "Second Number + Before Last Number Is Larger Than Middle Number\n";

    //.................................................................
    // Example 3
    int vals3[]{100, 200, 600, 400, 200};

    // Needed Output
    // "Middle Number Is The Largest" "600"
    n = sizeof(vals3) / sizeof(vals3[0]);
    if ((vals3[0] + vals3[n - 1]) > vals3[(n - 1) / 2])
        cout << "First Number + Last Number Is Larger Than Middle Number\n";
    else if ((vals3[1] + vals3[n - 2]) > vals3[(n - 1) / 2])
        cout << "Second Number + Before Last Number Is Larger Than Middle Number\n";
    else
        cout << "Middle Number Is The Largest\n";
}