
# tall project

"""
very tall > 200
180 < tall < 200
160 < normal < 180
150 < short < 160
very short < 150
"""
#  greeting the user
print("It's The Time To See Height Differently 😁")

# get the height
while True:
    try:
        tall = float(input("Enter The Height In CM: "))
        if tall > 0:
            break
        print("Invalid Input Height Should Be Bigger Than 0")
    except ValueError:
        print("invalid Input You Have To Type Numeric Value.")

if tall > 200:
    print("WOw! Very Tall")
elif 180 < tall <= 200:
    print("Tall")
elif  160 < tall <= 180:
    print("Normal")
elif 150 < tall <= 160:
    print("Short")
else:
    print("Very Short")

# ,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,

# even or odd project

print("=" * 50)

print("It's The Time To See If We Could Do Better 😎😉")

while True:
    try:
        number = float(input("Enter Number: "))
        number = int(number)
        break
    except ValueError:
        print("invalid Input You Have To Type Numeric Value.")

while True:
    guess = input(f"{number} is even or odd? 🙈🤔\n").strip().lower()
    if guess in ["odd" , "even"]:
        if (guess == "even" and number%2 == 0) or (guess == 'odd' and number%2 !=0):
            print("Bravooo!! 🥳🥳🥳💃")
            break
        else:
            print("No Problem Let's Tray Again 😀")
            break
    else:
        print(f"Sorry I Don't Understand {guess} 🙄🫤 you Should Type even Or odd")