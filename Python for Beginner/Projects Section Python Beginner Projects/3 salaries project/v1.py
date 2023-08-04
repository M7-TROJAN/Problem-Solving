""" Salaries Project:
A program that calculates the salary based on the number of working hours and hourly rate.
"""

# Ask the user for the number of working hours and validate the input
while True:
    try:
        number_of_hours = int(input("Enter the number of working hours: "))
        break
    except ValueError:
        print("Invalid input. Please enter a numeric value.")

# Ask the user for the hourly rate and validate the input
while True:
    try:
        rate = int(input("Enter the hourly rate: "))
        break
    except ValueError:
        print("Invalid input. Please enter a numeric value.")

# Calculate the salary and print it
salary = number_of_hours * rate
print(f"The salary is {salary}.")