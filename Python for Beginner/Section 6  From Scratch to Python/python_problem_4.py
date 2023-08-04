""" Calculator """

# get te first number
while True:
    try:
        firstNum = int(input("Enter First Number: "))
        break
    except ValueError:
        print("invalid input you must type numeric value")

# get the second number
while True:
    try:
        secondNum = int(input("Enter Second Number: "))
        break
    except ValueError:
        print("invalid input you must type numeric value")

# get the operator
op = input("Enter the operator ( + , - , * , / , % ): ")
while op not in ['+' , '-' , '*' , '/' , '%' ]:
    print("invalid input")
    op = input("Enter the operator ( + , - , * , / , % ): ")

#check if the user make ZeroDivisionError
if secondNum == 0 and op == '/':
    print("Error You Cannot division by zero ")
    exit(1)

# check op and make the process
match op:
    case '+':
        print(f"{firstNum} + {secondNum} = {firstNum+secondNum}")
    case '-':
        print(f"{firstNum} - {secondNum} = {firstNum-secondNum}")
    case '*':
        print(f"{firstNum} * {secondNum} = {firstNum*secondNum}")
    case '/':
        print(f"{firstNum} / {secondNum} = {firstNum/secondNum}")
    case '%':
        print(f"{firstNum} % {secondNum} = {firstNum%secondNum}")
