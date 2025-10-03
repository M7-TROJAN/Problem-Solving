#include <iostream>
#include <string>
#include <stack>
using namespace std;

void printNGE(int arr[], int size)
{
    int* NGE = new int[size];
    stack<int> stk;
    for (int i = size-1; i >= 0; --i)
    {
        int nge = -1;
        while (!stk.empty() && stk.top() <= arr[i])
        {
            stk.pop();
        }
        NGE[i] = stk.empty()? -1 : stk.top();
        stk.push(arr[i]);
    }
    for (size_t i = 0; i < size; i++)
    {
        cout << arr[i] << " -> " << NGE[i] << "\n";
    }
    delete [] NGE;
}

// Given a string, reverse it using stack. For example “Ahmed Mohamed” should be converted to “demahoM demhA”. 
// Hint
// • Create an empty stack. 
// • One by one push all characters of string to stack. 
// • One by one pop all characters from stack and put them back to strin

string ReversStringUsingStack(string originalString)
{
    stack<char> stk;
    char c;
    string outstring = "";
    int length = originalString.length();

    for (int i = 0; i < length; i++)
    {
        stk.push(originalString.at(i));
    }

    while(!stk.empty())
    {
        c = stk.top();
        outstring = outstring+c;
        stk.pop();
    }
    return outstring;
}

bool IsBracketsBalanced(const string& str) {
    stack<char> stk;

    for (char ch : str) {
        // If the character is an opening bracket
        if (ch == '(' || ch == '{' || ch == '[') {
            stk.push(ch);
        }
        // If the character is a closing bracket
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (stk.empty()) {
                return false; // Closing bracket with no matching opening bracket
            }
            char top = stk.top();
            stk.pop();

            // Check for mismatch between opening and closing brackets
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }

    // If the stack is empty at the end, brackets are balanced
    return stk.empty();
}

int main() {
    // test printNGE
    int arr[] = {1, 0, 5, 400, 2, 1, 15, 900, 20};
    printNGE(arr, 9);

    // test ReversStringUsingStack
    string originalString = "Ahmed Mohamed";
    cout <<"\noriginal String: " <<originalString << endl;
    string reversedString = ReversStringUsingStack(originalString);
    cout <<"reversed String: " <<reversedString << endl;

    // test IsBracketsBalanced
    string input;

    cout << "\nEnter a string of brackets: ";
    cin >> input;

    if (IsBracketsBalanced(input)) {
        cout << "Brackets are balanced." << endl;
    } else {
        cout << "Brackets are not balanced." << endl;
    }

    return 0;
}