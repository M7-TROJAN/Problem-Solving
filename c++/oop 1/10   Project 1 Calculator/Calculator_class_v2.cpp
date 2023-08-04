#include <iostream>
using namespace std;
class clsCalculator{
private:
    double _Result = 0; 
    double _PreviousResult = 0;
    float _LastNumber = 0;
    string _LastOperation;
    bool _zeroDivisionError = false;

public:
    void PerformOperation(char operation, double number) {
        switch (operation) {
            case '+':
                Add(number);
                break;
            case '-':
                Subtract(number);
                break;
            case '*':
                Multiply(number);
                break;
            case '/':
                Divide(number);
                break;
            default:
                cout << "Invalid operation\n";
                break;
        }
    }

    void Add(double number)
    {
        _LastNumber = number;
        _PreviousResult = _Result;
        _LastOperation = "Adding";
        _Result += number;
    }
    void Subtract(double number)
    {
        _LastNumber = number;
        _PreviousResult = _Result;
        _LastOperation = "Subtracting";
        _Result -= number;
    }
    void Divide(float number)
    {
        if (number == 0) {
            _zeroDivisionError = true;
            return;
        }
        _LastNumber = number;
        _PreviousResult = _Result;
        _LastOperation = "Dividing By";
        _Result /= number; 
    }
    void Multiply(float number)
    {
        _LastNumber = number;
        _PreviousResult = _Result;
        _LastOperation = "Multiplying";
        _Result *= number;
    }

    double GetFinalResult()
    {
        return _Result;
    }

    void Clear()
    {
        _LastNumber = 0;
        _PreviousResult = 0;
        _Result = 0;
        _LastOperation.clear();
        _zeroDivisionError = false;
    }

    void CancelLastOperation()
    {
        _LastNumber = 0;
        _LastOperation = "C.L.O"; // C.L.O stands for "Cancel Last Operation"
        _Result = _PreviousResult;
    }
    void PrintResult() 
    {
        if (_LastOperation.empty()) {
            cout << "Result = 0\n";
        } else if (_zeroDivisionError) {
            cout << "ZeroDivisionError: You Cannot Divide By Zero.\n";
            _zeroDivisionError = false;
        } else if (_LastOperation == "C.L.O") {
            cout << "Result After Cancelling Last Operation Is: " << _Result << "\n";
        } else {
            cout << "Result ";
            cout << "After " << _LastOperation << " " << _LastNumber << " is: " << _Result << "\n";
        }
    }
};

int main()
{
    clsCalculator calculator;

    calculator.PrintResult();
    
    calculator.Add(10.5);
    calculator.PrintResult();

    calculator.Add(11.5);
    calculator.PrintResult();

    calculator.Divide(0);
    calculator.PrintResult();

    calculator.Divide(1);
    calculator.PrintResult();

    calculator.Multiply(2);
    calculator.PrintResult();
    
    calculator.Subtract(2);
    calculator.PrintResult();

    calculator.CancelLastOperation();
    calculator.PrintResult();

    cout << calculator.GetFinalResult() << endl;

    calculator.Clear();

    calculator.PrintResult();

    calculator.PerformOperation('+', 20);
    calculator.PrintResult();
    calculator.PerformOperation('-', 2);
    calculator.PrintResult();
    calculator.PerformOperation('/', 4);
    calculator.PrintResult();
    calculator.PerformOperation('*', 3);
    calculator.PrintResult();
    calculator.PerformOperation('#', 3); // Invalid operation
}