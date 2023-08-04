#include <iostream>
using namespace std;

int main()
{
    int* ptrSize = new int;
    cout << "Enter total number of students: ";
    cin >> *ptrSize;
    const int studentsLength = *ptrSize;
    delete ptrSize;
    ptrSize = nullptr;

    float* studentsPtr;
    studentsPtr = new float[studentsLength]; // allocate memory for the array
    cout << "Enter grades of students." << endl;

    for (int i = 0; i < studentsLength; i++)
    {
        cout << "Student " << i + 1 << ": ";
        cin >> studentsPtr[i];
    }

    cout << "\nDisplaying grades of students." << endl;
    for (int i = 0; i < studentsLength; i++)
    {
        cout << "Student " << i + 1 << ": " << studentsPtr[i] << endl;
    }
    delete[] studentsPtr;
    studentsPtr = nullptr;
    return 0;
}


/*

In C++, you have several alternatives for dynamic memory allocation:

1- new operator: It is used to allocate memory for objects and calls their constructors to properly initialize them.

2- new[] operator: It is used to allocate memory for arrays of objects and calls their constructors for each element in the array.

3- delete operator: It is used to deallocate memory allocated by new and calls the destructors of the objects.

4- delete[] operator: It is used to deallocate memory allocated by new[] and calls the destructors of each object in the array.

5- Smart pointers: C++ provides smart pointer classes like std::unique_ptr and std::shared_ptr that handle dynamic memory management automatically.
They ensure proper deallocation of memory and help prevent memory leaks.

*/
