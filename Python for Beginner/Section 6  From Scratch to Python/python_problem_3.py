"""the greatest number is"""

x = int(input("Enter The First Number: "))
y = int(input("Enter The Second Number: "))
z = int(input("Enter The Third Number: "))

if x > y and x > z:
    print(f"{x} is the greatest Number")
elif y > x and y > z:
    print(f"{y} is the greatest Number")
else:
    print(f"{z} is the greatest Number")