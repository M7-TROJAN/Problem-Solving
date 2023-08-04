#include <string>
using namespace std;
string multi_table(int number)
{
    string table = "";
    for (int i = 1; i <= 10; i++)
    {
        table += to_string(i) + " * " + to_string(number) + " = " + to_string(i * number);
        if(i != 10)
            table += '\n';
    }
    return table;
}

// ........................................................................................

#include <string>
#include <sstream>
std::string multi_table(int number)
{
	std::ostringstream os;
	for (int i = 1; i <= 10; i++) {
		os << i << " * " << number << " = " << i*number << (i<10 ? "\n" : "");
	}
	return os.str();
}