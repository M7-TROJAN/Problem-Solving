#include <iostream>
#include <vector>
using namespace std;
bool ascendingCompare(int a, int b)
{
    return a < b;
}
bool descendingCompare(int a, int b)
{
    return a > b;
}
void customSort(vector<int>& numbersVector,bool(*compareFuncPtr)(int,int))
{
    for (int startIndex = 0; startIndex < numbersVector.size(); startIndex++)
    {
        int bestIndex = startIndex;
        for (int currentIndex = startIndex+1; currentIndex < numbersVector.size(); currentIndex++)
        {
            if(compareFuncPtr(numbersVector.at(currentIndex), numbersVector.at(bestIndex)))
                bestIndex = currentIndex;
        }
        swap(numbersVector.at(startIndex), numbersVector.at(bestIndex));
    }
}
void printVector(vector<int>& numbersVector)
{
    for(int i : numbersVector)
        cout << i << " ";
    cout << endl;
}
int main(void)
{
    vector<int> numbers = {2,5,1,3,6,4};
    bool (*compareFuncPtr)(int,int);

    // Print the elements of the vector before sorting.
    cout << "\nnumbers Vector Elements Is:\n";
    printVector(numbers);

// sort numbers In Ascending order
    // make compareFuncPtr point to ascendingCompare func
    compareFuncPtr = ascendingCompare;
    customSort(numbers,compareFuncPtr);
    cout << "numbers Vector After using customSort function in ascending order:\n";
    printVector(numbers);


// sort numbers In descending order
    // make compareFuncPtr point to ascendingCompare func
    compareFuncPtr = descendingCompare;
    customSort(numbers,compareFuncPtr);
    cout << "numbers Vector After using customSort function in descending order:\n";
    printVector(numbers);
}