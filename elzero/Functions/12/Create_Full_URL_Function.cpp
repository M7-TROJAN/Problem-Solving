#include <iostream>
using namespace std;

// Write Your Function Here
string createurl(string protocol, string siteName, string domain, bool worldWideWeb = true )
{
    string link = protocol + "://";
    if (worldWideWeb) {
        link += "www.";
    }
    link += siteName + "." + domain;
    return link;
}
int main()
{
    cout << createurl("https", "M7", "org") << "\n";             // https://www.M7.org
    cout << createurl("https", "google", "com", false) << "\n";  // https://google.com
    cout << createurl("http", "learn", "net") << "\n";           // http://www.learn.net
    return 0;
}