# Importing the datetime module to get the current year
import datetime

# Getting the current year from datetime module
current_year = datetime.datetime.now().year

# Starting an infinite loop to handle user input
while True:
    try:
        # Prompting the user to enter their birth year as an integer
        birth_year = int(input("Enter your birth year: "))
        # Exiting the loop if the user provides a valid input
        break
    except ValueError:
        # Catching the ValueError exception in case the user inputs a non-numeric value
        print("Invalid input. Please type a numeric value.")

# Calculating the user's age by subtracting their birth year from the current year
age = current_year - birth_year

# Printing the user's age as a formatted string
print(f"Your age is {age}.")
