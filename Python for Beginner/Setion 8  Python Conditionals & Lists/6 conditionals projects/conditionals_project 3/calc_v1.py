def get_number(s):
    while True:
        try:
            num = float(input(f"Enter {s} Number: "))
            break
        except ValueError:
            print("Invalid Input Please Enter A NUmeric Value.")
    return num

while True:
    #  get first number
    firstNum = get_number("First")

    # get the operator [+ , - , / , * , %]
    while True:
        operator = input("Enter The Operator (+, -, /, *, %, **): ")
        if operator in ['+' , '-' , '/' , '*' , '%' , '**']:
            break
        print("Invalid Operator. Operator should be like (+ - / * % **).")

    # get second Number
    secondNum = get_number("second")

    # calculator

    if operator == '+':
        operation_name = 'Addition'
        result = firstNum + secondNum
    elif operator == '-':
        operation_name = 'Subtraction'
        result = firstNum - secondNum
    elif operator == '*':
        operation_name = 'Multiplication'
        result = firstNum * secondNum
    elif operator == '/':
        operation_name = 'Division'
        try:
            result = firstNum / secondNum
        except ZeroDivisionError:
            result = None
            print("Error You Cannot Divide By Zero.")
    elif operator == '%':
        operation_name = 'modulo'
        result = firstNum % secondNum
    elif operator == '**':
        operation_name = "power"
        result = firstNum ** secondNum

    if result is not None:
        print("=" * 30)
        print(f'{operation_name} result is {result:.1f}')
        print(f"{firstNum} {operator} {secondNum} = {result:.1f}")

    print("=" * 30)
    print("You wanna To Make Another Operator?(y/n)")
    again = input("y means yes otherwise means no\n")
    if again not in {"y" , "yes"}:
        break

    print("\nNew Operation\n")
