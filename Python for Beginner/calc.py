
# calculator program

# main loop
while True:
    # input first number
    while True:
        try:
            num1 = float(input("enter 1st number: "))
            break
        except ValueError:
            print("invalid input. please enter a numeric value")  # numeric means رقمي

    # input operation
    while True:
        try:
            op = input("enter operation type: ")
            if op in ['/', '*', '-', '+', '%']:
                break
            raise ValueError
        except ValueError:
            print("invalid operator, please enter (* , / , + , - , %)")

    # input second number
    while True:
        try:
            num2 = float(input("enter 2ed number: "))
            # cheek if the user make ZeroDivisionError
            if op == '/' and num2 == 0:
                raise ZeroDivisionError
            break
        except ValueError:
            print("invalid input. please enter a numeric value")   # numeric means رقمي
        except ZeroDivisionError:
            print("cannot divide by zero please enter another numeric value")

    # print the result
    match op:
        case '+':
            print(f"{num1} + {num2} = {num1 + num2 }")
        case '-':
            print(f"{num1} - {num2} = {num1 - num2 }")
        case '*':
            print(f"{num1} * {num2} = {num1 * num2 }")
        case '/':
            print(f"{num1} / {num2} = {num1 / num2 }")
        case '%':
            print(f"{num1} % {num2} = {num1 % num2 }")
        case _:
            print(None)

    # cheek if the user want to preform another operation
    while True:
        try:
            repeat = input("You want to preform another operator (y/n)?: ")
            if repeat in ('n', 'y'):
                break
            raise ValueError
        except ValueError:
            print("Error Just Enter (y) for yes (n) for no")

    if repeat == 'n':
        break # break from the main loop
