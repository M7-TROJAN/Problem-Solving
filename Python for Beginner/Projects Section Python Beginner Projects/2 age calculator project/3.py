""" Importing the datetime module to get the current year """
import datetime

current_date = datetime.datetime.now()

# Getting the current year, month and day from the current_date object
current_year = current_date.year
current_month = current_date.month
current_day = current_date.day

while True:
    try:
        # Prompting the user to enter their birth year, month and day as integers
        birth_year = int(input("Enter your birth year: "))
        birth_month = int(input("Enter your birth month (1-12): "))
        birth_day = int(input("Enter your birth day (1-31): "))
        # Exiting the loop if the user provides valid inputs and bigger than zero
        if birth_year > 0 and birth_month > 0 and birth_day > 0:
            break
    except ValueError:
        # Catching the ValueError exception in case the user inputs a non-numeric value
        print("Invalid input. Please type a numeric value.")

# Creating a datetime object with the user's birth year, month and day
birth_date = datetime.datetime(birth_year, birth_month, birth_day)

# Calculating the user's age by subtracting their birth date from the current date
age = current_date - birth_date

# Extracting the number of years from the age object
age_in_years = int(age.days / 365.25)

# Printing the user's age as a formatted string
print(f"You are {age_in_years} years, {age.days % 365} days, {age.seconds // 3600} hours and {age.seconds % 3600 // 60} minutes old.")
