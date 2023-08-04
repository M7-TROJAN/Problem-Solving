""" version 1"""
# while True:
#     try:
#         first_num, operator, second_num = input('Enter The Operation: ').split(" ")
#         break
#     except ValueError:
#         print("Invalid Input Enter Your Operation Like (1 + 1)")
# if not (first_num.isdigit() and second_num.isdigit()):
#     print("Invalid Input")
#     exit()
# if operator not in ['/' , '*' , "+" , "-" , "%","x",]:
#     print("Invalid Operator")
#     exit()

# first_num , second_num = float(first_num) , float(second_num)

# print('-'*20)
# if operator in ["*" , "x"]:
#     print(f"{first_num} {operator} {second_num} = {first_num*second_num}")
# elif operator == '/':
#     if second_num != 0:
#         print(f"{first_num} {operator} {second_num} = {first_num/second_num}")
#     else:
#         print("Error You Cannot Division By Zero.")
#         exit()
# elif operator == '+':
#     print(f"{first_num} {operator} {second_num} = {first_num+second_num}")
# elif operator == '-':
#     print(f"{first_num} {operator} {second_num} = {first_num-second_num}")
# elif operator == '%':
#     print(f"{first_num} {operator} {second_num} = {first_num%second_num}")


# .........................................................................................................

""" version 2"""
# while True:
#     try:
#         # Get input from the user and split it into first_num, operator, and second_num
#         # The input should be in the format: first_num operator second_num
#         first_num, operator, second_num = input('Enter The Operation: ').split(" ")
#         break
#     except ValueError:
#         # If the input is not in the correct format, print an error message and try again
#         print("Invalid Input")
#         print("The input should be in the format: first_num operator second_num Like (1 + 1)")

# # Check if first_num and second_num are valid numbers
# if not (first_num.replace(".", "").isdigit() and second_num.replace(".", "").isdigit()):
#     print("Invalid Input")
#     exit()

# # Check if the operator is valid
# if operator not in ['/' , '*' , "+" , "-" , "%","x",]:
#     print("Invalid Operator")
#     exit()

# # Convert first_num and second_num to float
# first_num , second_num = float(first_num) , float(second_num)

# print('-'*20)

# # Perform the operation based on the operator entered by the user
# if operator in ["*" , "x"]:
#     print(f"{first_num} {operator} {second_num} = {first_num*second_num}")
# elif operator == '/':
#     if second_num != 0:
#         print(f"{first_num} {operator} {second_num} = {first_num/second_num}")
#     else:
#         print("Error You Cannot Division By Zero.")
#         exit()
# elif operator == '+':
#     print(f"{first_num} {operator} {second_num} = {first_num+second_num}")
# elif operator == '-':
#     print(f"{first_num} {operator} {second_num} = {first_num-second_num}")
# elif operator == '%':
#     print(f"{first_num} {operator} {second_num} = {first_num%second_num}")


# .........................................................................................................
""" version 3"""
while True:
    try:
        # Get input from user
        first_num, operator, second_num = input('Enter The Operation: ').split(" ")
        
        # Check if first_num and second_num are valid numbers
        if not (first_num.replace(".", "").isdigit() and second_num.replace(".", "").isdigit()):
            raise ValueError("Invalid Input")

        # Check if the operator is valid
        if operator not in ['/' , '*' , "+" , "-" , "%","x",]:
            raise ValueError("Invalid Operator")

        # Convert first_num and second_num to float
        first_num , second_num = float(first_num) , float(second_num)

        print('-'*20)
        # Perform the operation based on the operator entered by the user
        if operator in ["*" , "x"]:
            print(f"{first_num} {operator} {second_num} = {first_num*second_num}")
        elif operator == '/':
            if second_num != 0:
                print(f"{first_num} {operator} {second_num} = {first_num/second_num}")
            else:
                raise ZeroDivisionError("Cannot divide by zero")
        elif operator == '+':
            print(f"{first_num} {operator} {second_num} = {first_num+second_num}")
        elif operator == '-':
            print(f"{first_num} {operator} {second_num} = {first_num-second_num}")
        elif operator == '%':
            print(f"{first_num} {operator} {second_num} = {first_num%second_num}")
    except Exception as e:
        print(f"Error: {e}")
    
    # Ask the user if they want to perform another operation
    choice = input("Do you want to perform another operation? (y/n): ").lower()
    if choice == "n":
        break
