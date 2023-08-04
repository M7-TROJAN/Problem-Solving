# Employees and their offices
cairo = ['Islam Mahfouz','Mohamed Gouda', 'Hatem Medhat', "Mahmoud Mattar"]
riyadh = ['Ayman Hamed', 'Seif Ali', 'Adham Wael']
casablanca = ['Ahmed Ashraf', 'Mahrous Samy', 'Amr Ahmed' ]
dubai = ['Ahmed Alaa', 'Kareem Ayman', 'Osama Ashraf']

# get the name of employee
name = input ("Enter the name of the employee: ").title()

# check employee's office
if name in cairo:
    office = "cairo"
elif name in riyadh:
    office = "riyadh"
elif name in casablanca:
    office = "casablanca"
elif name in dubai:
    office = "dubai"
else:
    office = None

if office:
    print(f"{name} Works In {office} Office.")
else:
    print("The Employee Is Not Found.")
