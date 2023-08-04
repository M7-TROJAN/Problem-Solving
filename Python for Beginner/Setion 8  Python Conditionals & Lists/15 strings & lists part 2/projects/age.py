import datetime

# Get current date and time
now = datetime.datetime.now()

# Extract year, month, and day from the current date
current_year = now.year
current_month = now.month
current_day = now.day

# Get the user's full name
name = input("Enter Your Full Name: ").strip().title()

# Get the user's birth date
while True:
    try:
        birth_date = input("Enter Your Birthdate (dd-mm-yyyy): ").strip()

        # Split the input into day, month, and year
        day, month, year = birth_date.split("-")

        # Check if the input is valid
        if (day.isdigit() and month.isdigit() and year.isdigit()):
            if 0 <= len(day) <= 30 and 0 <= len(month) <= 12 and len(year) == 4:
                break
        raise ValueError

    except ValueError:
        # Prompt the user to enter the date in the correct format
        print("Invalid input format. Please enter the date in the format dd-mm-yy.")

# Get the user's first name
first_name = name.split()[0]

# Calculate the user's age in years, months, and days
age = {
    "year": current_year - int(year),
    "month": current_month - int(month),
    "day": current_day - int(day)
}

# Print the user's age
print('-' * 20)
print(f'Hello, {first_name}\nWelcome at Age Calculator')
print('-' * 20)
print(f'Your Age Is: {age["year"]} Year, {age["month"]} Month And {age["day"]} Day.')
