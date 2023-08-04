# Employees and their offices
offices = {
    'cairo': ['Islam Mahfouz', 'Mohamed Gouda', 'Hatem Medhat', 'Mahmoud Mattar'],
    'riyadh': ['Ayman Hamed', 'Seif Ali', 'Adham Wael'],
    'casablanca': ['Ahmed Ashraf', 'Mahrous Samy', 'Amr Ahmed'],
    'dubai': ['Ahmed Alaa', 'Kareem Ayman', 'Osama Ashraf']
}

# get office name
office = input ("Enter The Name Of The Office: ").strip().lower()

# print the employees in that office

match office:
    case "cairo":
        print("=" * 20)
        for employee in offices[office]:
            print(f"{employee}")
    case "riyadh":
        print("=" * 20)
        for employee in offices[office]:
            print(f"{employee}")
    case "casablanca":
        print("=" * 20)
        for employee in offices[office]:
            print(f"{employee}")
    case "dubai":
        print("=" * 20)
        for i, employee in enumerate(offices[office]):
            print(f"{i+1}. {employee}")
    case _:
        print("The Office Is Not Found.")