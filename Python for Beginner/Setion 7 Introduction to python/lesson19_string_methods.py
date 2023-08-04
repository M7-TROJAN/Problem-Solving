
# lower()
    # convert all characters in the string to lowercase
#syntax:
    # string.lower()
"MAHMOUD".lower() # -> mahmoud

#.......................................................................

# upper()
    # convert all characters in the string to uppercase
#syntax:
    # string.upper()
"mahmoud".upper() # -> MAHMOUD

#..................................................................

# capitalize()
    # convert the first character in the string to uppercase
#syntax:
    # string.capitalize()
"mahmoud".capitalize() # -> Mahmoud

#..................................................................

# title()
    # Converts the first character of each word to upper case
#syntax:
    # string.title()
"mahmoud mohamed abdalaziz".title() # -> Mahmoud Mohamed Abdalaziz

#..................................................................

# replace()
    # Returns a string where a specified value is replaced with a specified value
    # Usually it takes two arguments old value and new value and return the string when old value replaced by new value
    # you can add third argument its int count  it's a number of characters will replaced
#syntax:
    # string.replace(oldvalue , newvalue , count)
"mahmoud mohamed abdalaziz".replace(" " , "") # -> mahmoudmohamedabdalaziz

#..................................................................

# f string

num = 1000000
print(f"{num}") # 1000000
print(f"{num:,}") # 1,000,000

num2 = 1 / 3
print(f"{num2}")  # 0.3333333333333333
print(f"{num2:.2f}") # 0.33
print(f"{num2:.3f}") # 0.333

# using c format
print("%.2f" %(num2)) # 0.333

#......................................................................

print(0.1 + 0.1 == 0.3)