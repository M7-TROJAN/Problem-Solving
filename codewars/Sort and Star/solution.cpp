#include <vector>
#include <string>
#include <algorithm>
using namespace std;
string twoSort(vector<string> s)
{
    sort(s.begin(), s.end());
    string result = "";

    for (int i = 0; i < s.front().size(); i++)
    {
        result += s.front()[i];
        if (i != s.front().size() - 1)
            result += "***";
    }
    return result;
}

// ......................................................................

// another solution

#include <algorithm>
#include <string>
#include <vector>
using namespace std;
string twoSort(vector<string> s)
{
    sort(s.begin(), s.end());
    string result = s.at(0);
    for (int i = 1; i < result.size(); i += 4)
        result.insert(i, "***");
    return result;
}

// ......................................................................

// another solution

#include <algorithm>
#include <string>
using namespace std;
string twoSort(vector<string> s)
{
    string result = *min_element(s.begin(), s.end());
    for (int i = 1; i < result.size(); i += 4)
        result.insert(i, "***");
    return result;
/*
min_element(s.begin(), s.end()); => returns a pointer pointed to the the minumum element  
*/
}
