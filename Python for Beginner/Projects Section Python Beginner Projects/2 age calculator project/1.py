""" age calculator project """

# ask the user for his birth year
birthYear = int(input("enter your birth year: "))

#  get current year
currentYear = int(input("enter current year: "))

# subtract birth year from current year
age = currentYear - birthYear

# print age
print(f"your age is {age}")