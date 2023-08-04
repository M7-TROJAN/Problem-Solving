#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s[n];

    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < s[i].size(); j++)
        {
            if (j % 2 == 0)
            {
                cout << s[i][j];
            }
        }

        cout << " ";

        for (int x = 0; x < s[i].size(); x++)
        {
            if (x % 2 != 0)
                cout << s[i][x];
        }

        cout << "\n";
    }

    return 0;
}
