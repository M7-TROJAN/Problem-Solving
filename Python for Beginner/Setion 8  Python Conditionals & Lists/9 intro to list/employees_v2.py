# bonus for juniors is 3 months salary
# bonus for mid level is 6 months salary
# bonus for seniors is 9 months salary

# A dictionary mapping employee levels to bonus multipliers
EMPLOYEE_BONUS = {
    "juniors": 3,
    "mid_level": 6,
    "seniors": 9,
}

# A dictionary mapping employee levels to lists of employee IDs
EMPLOYEES_ID = {
    "juniors": ['1111', '1113', '1115', '1117', '1119', '1121'],
    "mid_level": ['1311', '1313', '1315', '1317', '1319', '1321', '1323', '1325'],
    "seniors": ['1519', '1521', '1523', '1525'],
}

# main function
def main():
    """Calculate the bonus for an employee based on their hourly rate and hours worked per month."""

    # Get employee ID
    employee_id = input("Enter Employee Id: ")

    # Determine employee level based on employee ID
    employee_level = None
    for level, ids in EMPLOYEES_ID.items():
        if employee_id in ids:
            employee_level = level
            break

    # Check if employee ID is valid
    if employee_level is None:
        print(f"{employee_id} is not a valid employee ID.")
        exit(1)

    # Get hourly rate and hours worked per month from user input
    hourly_rate = get_number("Hourly rate")
    hours_worked_per_month = get_number("Hours worked this month")

    # Calculate salary
    salary = hourly_rate * hours_worked_per_month

    # Calculate bonus based on employee level
    bonus_multiplier = EMPLOYEE_BONUS[employee_level]
    bonus_amount = salary * bonus_multiplier

    # Print results
    print("=" * 40)
    print(f"Employee ID: {employee_id} gets a bonus of {bonus_amount} EGP.")


def get_number(prompt):
    """Get a positive integer from the user."""
    while True:
        try:
            num = int(input(f"Enter {prompt}: "))
            if num < 0:
                print(f"Error: {prompt} should be bigger than zero.")
            else:
                break
        except ValueError:
            print("Invalid input: you should enter a numeric value.")
    return num


if __name__ == "__main__":
    main()
