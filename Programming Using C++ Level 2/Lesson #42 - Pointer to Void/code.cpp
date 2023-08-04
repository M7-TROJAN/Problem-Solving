#include <iostream>
using namespace std;
int main()
{
    void *ptr;

    float f1 = 10.5;
    ptr = &f1;
    cout << ptr << endl; // the address of f1
    cout << *(static_cast<float *>(ptr)) << endl; // the value that pointed by the void pointer => 10.5

    cout << "====================\n";

    int x = 50;
    ptr = &x;
    cout << ptr << endl; // the address of x
    cout << *(static_cast<int *>(ptr)) << endl; // the value that pointed by the void pointer => 50

    cout << "====================\n";

    string str = "mahmoud";
    ptr = &str;
    cout << ptr << endl; // the address of str
    cout << *(static_cast<string *>(ptr)) << endl; // the value that pointed by the void pointer => mahmoud

    cout << "====================\n";
    return 0;
}

// static_cast<int*>(ptr)      means => حولي نوع المؤشر ده لنوع اينتجر
// static_cast<string*>(ptr)   means => حولي نوع المؤشر ده لنوع سترينج
// static_cast<float*>(ptr)    means => حولي نوع المؤشر ده لنوع فلوت

/*
    للنوع المناسب الي انت محتاجه void علشان تحول البوينتر الي من نوع  static_cast  باختصار انت بتستخدم امر
*/