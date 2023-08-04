""" Salaries Project:
    A program that calculates the salary based on the number of working hours and hourly rate. """

# Prompting the user to enter the employee name
employee_name = input("Enter employee name: ")

# Asking the user for the number of working hours and validating the input
while True:
    try:
        number_of_hours = int(input("Enter the number of working hours: "))
        break
    except ValueError:
        print("Invalid input. Please enter a numeric value.")

# Asking the user for the hourly rate and validating the input
while True:
    try:
        rate = float(input("Enter the hourly rate: "))
        break
    except ValueError:
        print("Invalid input. Please enter a numeric value.")

# Calculating the salary based on the number of hours worked and hourly rate
salary = number_of_hours * rate

# Printing the employee name and salary as a formatted string
print(f"{employee_name}'s salary is {salary}.")
