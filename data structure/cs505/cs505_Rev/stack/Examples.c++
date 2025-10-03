#include <iostream>
using namespace std;

template <class T>
class StackArray {
private:
    T* arr;
    int capacity;
    int topIndex;
    void resize() {
        capacity *= 2;
        T* newArray = new T[capacity];
        for (int i = 0; i <= topIndex; i++)
        {
            newArray[i] = arr[i];
        }
        delete [] arr;
        arr= newArray;
    }
public:
    StackArray(int initialCapacity = 10) : capacity(initialCapacity), topIndex(-1) 
    {
        arr = new T[capacity];
    }

    ~StackArray() {
        delete [] arr;
    }

    void Push(const T& value)
    {
        if(IsFull())
            resize();
        arr[++topIndex] = value;
    }

    void Pop()
    {
        if (IsEmpty())
        {
            return;
            // throw underflow_error("Stack underflow: Cannot pop from an empty stack.");
        }
        topIndex--;
    }

    T Top()
    {
        if (IsEmpty())
        {
            throw underflow_error("Stack is empty: No top element.");
        }
        return arr[topIndex];
    }

    bool IsFull() const {
        return topIndex + 1 == capacity;
    }

    int Size() const {
        return topIndex + 1;
    }

    int Capacity() const {
        return capacity;
    }
    
    bool IsEmpty() const
    {
        return topIndex == -1;
    }

    bool Contains(const T& value) const
    {
        if(IsEmpty) return false;

        for (int i = 0; i <= topIndex; i++)
        {
            if(arr[i] == value)
                return true;
        }
        return false;
    }

    void Shrink() {
        if (Size() <= capacity / 4 && capacity > 10) {
            capacity /= 2;
            T* newArray = new T[capacity];
            for (int i = 0; i <= topIndex; i++) {
                newArray[i] = arr[i];
            }
            delete [] arr;
            arr = newArray;
        }
    }

    void Reverse()
    {
        StackArray<T> temp;
        T element;

        while (!IsEmpty())
        {
            element = Top();
            Pop();
            temp.Push(element);
        }
        
        while (!temp.IsEmpty())
        {
            element = temp.Top();
            temp.Pop();
            Push(element);
        }
    }
};

void PrintNGE(int arr[], const int& size)
{
    int *nge = new int[size];
    StackArray<int> stk;

    for (int i = size-1; i >= 0; i--)
    {
        while (!stk.IsEmpty() && stk.Top() <= arr[i])
        {
            stk.Pop();
        }
        
        nge[i] = stk.IsEmpty()? -1 : stk.Top();

        stk.Push(arr[i]);
    }

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " - " << nge[i] << endl;
    }
    
    delete [] nge;
}

// Given a string, reverse it using stack. For example “Ahmed Mohamed” should be converted to “demahoM demhA”. 
// Hint
// • Create an empty stack. 
// • One by one push all characters of string to stack. 
// • One by one pop all characters from stack and put them back to strin

string ReverseString(const string& str)
{
    string reversedStr;
    StackArray<char> stk;

    for (int i = 0; i < str.length(); i++)
    {
        stk.Push(str[i]);
    }
    
    while (!stk.IsEmpty())
    {
        reversedStr += stk.Top();
        stk.Pop();
    }
    return reversedStr;
}

string ReversStringUsingStack(string originalString)
{
    StackArray<char> stk;
    char c;
    string outstring = "";
    int length = originalString.length();

    for (int i = 0; i < length; i++)
    {
        stk.Push(originalString.at(i));
    }

    while(!stk.IsEmpty())
    {
        c = stk.Top();
        outstring = outstring+c;
        stk.Pop();
    }
    return outstring;
}

bool IsBracketsBalanced(const string& str) {

    StackArray<char> stk;
    int length = str.length();

    for (int i = 0; i < length; i++)
    {
        if(str[i] == '(' || str[i] == '{' || str[i] == '[')
            stk.Push(str[i]);

        else if(str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            if(stk.IsEmpty())
                return false;
            
            char top = stk.Top();
            stk.Pop();

            if( str[i] == ')' && top != '(' ||
                str[i] == '}' && top != '{' ||
                str[i] == ']' && top != '[')
            {
                return false;
            }
        }
    }
    
    // If the stack is empty at the end, brackets are balanced
    return stk.IsEmpty();
}

int main() {

    int arr[] = {1, 0, 5, 400, 2, 1, 15, 900, 20};
    PrintNGE(arr, 9);

    cout << ReverseString("Mahmoud Mattar") << endl;

    cout << "IsBracketsBalanced: " << (IsBracketsBalanced("((({}[])))") ? "true" : "false") << endl;
    cout << "IsBracketsBalanced: " << (IsBracketsBalanced("((({}[)))") ? "true" : "false") << endl;
}


