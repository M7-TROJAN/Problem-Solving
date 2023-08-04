
# "اجبار"
# Forcing the user to enter a number, not a letter by using try:


# first example
while True:
    try:
        x = int(input("x:"))
        y = int(input("y: "))
        break                   # break her from the loop if the input for x and y is valid
    except ValueError:
        # If an error occurs, of type ValueError, execute this statement
        # قم بتنفيذ هذه الاوامر ValueError لو حدث اي خطأ من نوع 
        print("valid input")
print(x+y)



# second example
while True:
    try:
        x = int(input("x:"))
        break                # break her from the loop if the input for x is valid
    except ValueError:
        # If an error occurs, of type ValueError, execute this statement
        print("valid input")

while True:
    try:
        y = int(input("y:"))
        break                # break her from the loop if the input for y is valid
    except ValueError:
        # If an error occurs, of type ValueError, execute this statement
        print("valid input")
print(x+y)
