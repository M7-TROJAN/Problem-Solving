#include <iostream>
using namespace std;
int main()
{
    int size;
    cout << "Enter total number of students: ";
    cin >> size;

    float *studentsPtr;
    // memory allocation of num number of floats
    studentsPtr = new float[size];
    cout << "Enter grades of students." << endl;

    for (int i = 0; i < size; i++)
    {
        cout << "Student" << i + 1 << ": ";
        cin >> *(studentsPtr + i);
    }
    cout << "\nDisplaying grades of students." << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Student" << i + 1 << ": " << *(studentsPtr + i) << endl;
    }
    // ptr memory is released
    delete[] studentsPtr;
    studentsPtr = NULL;
    return 0;
}

