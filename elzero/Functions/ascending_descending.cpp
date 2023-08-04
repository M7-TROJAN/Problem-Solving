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
void sortAscending(vector<int>& numbersVector)
{
    for (int startIndex = 0; startIndex < numbersVector.size(); startIndex++)
    {
        int bestIndex = startIndex;
        for (int currentIndex = startIndex+1; currentIndex < numbersVector.size(); currentIndex++)
        {
            if(ascendingCompare(numbersVector.at(currentIndex), numbersVector.at(bestIndex)))
                bestIndex = currentIndex;
        }
        swap(numbersVector.at(startIndex), numbersVector.at(bestIndex));
    }
}
void sortDescending(vector<int>& numbersVector)
{
        for (int startIndex = 0; startIndex < numbersVector.size(); startIndex++)
    {
        int bestIndex = startIndex;
        for (int currentIndex = startIndex+1; currentIndex < numbersVector.size(); currentIndex++)
        {
            if(descendingCompare(numbersVector.at(currentIndex), numbersVector.at(bestIndex)))
                bestIndex = currentIndex;
        }
        swap(numbersVector.at(startIndex), numbersVector.at(bestIndex));
    }
}
void printNumbers(vector<int>& numbersVector)
{
    for(int i : numbersVector)
        cout << i << " ";
    cout << endl;
}
int main(void)
{
    vector<int> numbers1 = {9,2,7,3,1,4,5,0,6,-11,10,34};
    cout << "numbers1 Vector befor using sortAscending function:\n";
    printNumbers(numbers1);

    sortAscending(numbers1);

    cout << "numbers1 Vector After using sortAscending function:\n";
    printNumbers(numbers1);

    cout << "\n====================================================\n\n";

    vector<int> numbers2 = {500,40,23,10,0,-4,9,4,7,2,354};
    cout << "numbers1 Vector befor using sortDescending function:\n";
    printNumbers(numbers2);

    sortDescending(numbers2);

    cout << "numbers1 Vector After using sortDescending function:\n";
    printNumbers(numbers2);
}