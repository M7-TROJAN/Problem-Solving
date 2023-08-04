# Employees and their offices
cairo = ['Islam Mahfouz','Mohamed Gouda', 'Hatem Medhat', "Mahmoud Mattar"]
riyadh = ['Ayman Hamed', 'Seif Ali', 'Adham Wael']
casablanca = ['Ahmed Ashraf', 'Mahrous Samy', 'Amr Ahmed' ]
dubai = ['Ahmed Alaa', 'Kareem Ayman', 'Osama Ashraf']

# get office name
office = input ("Enter The Name Of The Office: ").strip().lower()

# print the employees in that office
match office:
    case "cairo" | "egypt" | "eg":
        print("=" * 20)
        for i , employee in enumerate(cairo):
            print(f"{i+1}. {employee}")
    case "riyadh" | "saudi arabia" | "ksa":
        print("=" * 20)
        for i , employee in enumerate(riyadh):
            print(f"{i+1}. {employee}")
    case "casablanca" | "morocco":
        print("=" * 20)
        for i , employee in enumerate(casablanca):
            print(f"{i+1}. {employee}")
    case "dubai" | "uae":
        print("=" * 20)
        for i , employee in enumerate(dubai):
            print(f"{i+1}. {employee}")
    case _:
        print("The office Is Not Found.")