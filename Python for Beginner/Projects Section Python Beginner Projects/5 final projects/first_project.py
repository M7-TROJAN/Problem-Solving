# List of available currencies
currencies = ["DOLLAR", "EGYPTIAN POUND", "EURO"]

# Prompt user for name and strip leading/trailing spaces
name = input("Name: ").strip().title()

# Prompt user for currency and validate input
while True:
    currency = input("Currency: ")
    if currency.upper() in currencies:
        break

# Prompt user for number of hours and validate input
while True:
    try:
        number_of_hours = int(input("Number of hours: "))
        if number_of_hours > 0:
            break
    except ValueError:
        print("Invalid input. Please enter a numeric value.")

# Prompt user for hourly rate and validate input
while True:
    try:
        rate = float(input("Hourly Rate: "))
        if rate > 0:
            break
    except ValueError:
        print("Invalid input. Please enter a numeric value.")

# Calculate and print salary with currency
salary = number_of_hours * rate

print(f"The salary of {name} is {salary} {currency}.")

