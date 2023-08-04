#include <string>
using namespace std;
string bonus_time(int salary, bool bonus)
{
    string total = "$";
    if (bonus)
        return total += to_string(salary * 10);
    return total += to_string(salary);
}

// ...................................................

#include <string>
using namespace std;
string bonus_time(int salary, bool bonus)
{

    return (bonus) ? ("$" + to_string(salary * 10)) : ("$" + to_string(salary));
}