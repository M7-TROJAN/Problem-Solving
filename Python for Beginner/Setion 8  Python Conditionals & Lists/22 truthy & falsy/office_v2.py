# Employees and their offices
offices = {
    'cairo': ['Islam Mahfouz', 'Mohamed Gouda', 'Hatem Medhat', 'Mahmoud Mattar'],
    'riyadh': ['Ayman Hamed', 'Seif Ali', 'Adham Wael'],
    'casablanca': ['Ahmed Ashraf', 'Mahrous Samy', 'Amr Ahmed'],
    'dubai': ['Ahmed Alaa', 'Kareem Ayman', 'Osama Ashraf']
}

# get the name of employee
name = input("Enter the name of the employee: ").title()

# check employee's office
for office, employees in offices.items():
    if name in employees:
        print(f"{name} works in {office} office.")
        break
else:
    print("The employee is not found.")
