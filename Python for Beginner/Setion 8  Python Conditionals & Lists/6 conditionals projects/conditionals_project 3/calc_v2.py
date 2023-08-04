def get_number(s):
    """
    This function takes a string 's' and prompts the user to enter a numeric value.
    If the entered value is not numeric, the function prints an error message and prompts the user to try again.
    The function keeps prompting until a valid numeric value is entered, and then returns the value.
    """
    while True:
        try:
            num = float(input(f"Enter {s} Number: "))
            break
        except ValueError:
            print("Invalid Input Please Enter A Numeric Value.")
    return num


while True:
    # Prompt the user to enter the first number
    firstNum = get_number("First")

    # Prompt the user to enter the operator
    while True:
        operator = input("Enter The Operator (+, -, /, *, %): ")
        if operator in ['+' , '-' , '/' , '*' , '%']:
            break
        print("Invalid Operator. Operator should be like (+ - / * %).")

    # Prompt the user to enter the second number
    secondNum = get_number("second")

    # Calculate the result based on the operator entered
    if operator == '+':
        result = firstNum + secondNum
    elif operator == '-':
        result = firstNum - secondNum
    elif operator == '*':
        result = firstNum * secondNum
    elif operator == '/':
        try:
            result = firstNum / secondNum
        except ZeroDivisionError:
            result = None
            print("Error You Cannot Divide By Zero.")
    elif operator == '%':
        result = firstNum % secondNum

    # Print the result if it is not None
    if result is not None:
        print("=" * 30)
        print(f"{firstNum} {operator} {secondNum} = {result}")

    # Ask the user if they want to perform another operation
    print("Do you want to perform another operation? (y/n)")
    again = input("Enter 'y' for yes, anything else for no: ")
    if again not in {"y" , "yes"}:
        break

    # Print a newline and start a new operation
    print("\nNew Operation\n")
