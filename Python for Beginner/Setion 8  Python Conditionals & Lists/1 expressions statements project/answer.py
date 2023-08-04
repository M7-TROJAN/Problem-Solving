# The regular number of working hours per month
REGULAR_HOURS = 100
# The overtime rate for extra hours worked
OVERTIME_RATE = 2

def main():
    """Main function that prompts user for input and calls calculate_salary"""
    # Get employee's name, number of hours worked, and hourly rate from user input
    name = input("Enter employee's name: ").strip().title()
    num_hours = input("Enter the number of hours worked per month: ")
    rate = input("Enter your hourly rate: ")
    print('-'*20)
    # Call calculate_salary function and print the result
    print(calculate_salary(name, num_hours, rate))


def calculate_salary(name, num_hours, rate):
    """Function that calculates the employee's monthly salary"""
    try:
        # Convert num_hours and rate to float
        num_hours = float(num_hours)
        rate = float(rate)
    except ValueError:
        # Return an error message if num_hours or rate is not a number
        return "Error: Please enter numeric values for hours worked and hourly rate."

    # Calculate salary based on regular hours and overtime hours worked
    if num_hours > REGULAR_HOURS:
        over_hours = num_hours - REGULAR_HOURS
        salary = (REGULAR_HOURS * rate) + (over_hours * rate * OVERTIME_RATE)
    else:
        salary = num_hours * rate

    # Return the employee's name, number of hours worked, and monthly salary
    return f"{name} has worked {num_hours} hours this month. His salary is {salary:,.2f}$"

main()