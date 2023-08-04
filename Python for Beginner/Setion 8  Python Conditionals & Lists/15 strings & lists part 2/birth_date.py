

# Prompt user to enter their birth date in the format "dd-mm-yy"
birth_date = input("Enter Your Birth Date (dd-mm-yy): ").strip()

try:
    # Extract day, month, and year from the input using the .split() method
    day , month , year = birth_date.split("-")
    print(day, month, year)
except ValueError:
    # If the user enters an invalid format, catch the ValueError and display an error message
    print("Invalid input format. Please enter the date in the format dd-mm-yy.")
