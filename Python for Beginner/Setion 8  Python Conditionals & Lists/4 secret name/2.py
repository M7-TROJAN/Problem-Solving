# Print a greeting message to the user
print("It's THe Time To See If We Could Do Better😀")

# Loop until the user enters a valid integer
while True:
    try:
        number = int(input("Enter The NUmber: "))
        break
    except ValueError:
        print("Invalid Input Please Type Numeric value ")

while True:
    try:
        divide_by = int(input("Enter The NUmber to divide by: "))
        break # Break the loop if the user enters a valid integer
    except ValueError:
        print("Invalid Input Please Type Numeric value ")

while True:
    # Ask the user if the number is divided by divide_by
    answer = input(f"{number} is divide by {divide_by} or NO? 🤔🤔\n(y/n)?: ").strip().lower()
    # Check if the answer is valid (yes, y, no, or n)
    if answer in ["yes", "y", "no", "n"]:
        # Check if the answer is yes and the number is divisible by divide_by or
        # if the answer is no and the number is not divisible by divide_by
        if (answer in ["yes", "y"] and number % divide_by == 0) or \
            (answer in ["no", "n"] and number % divide_by != 0):
            print("Bravooo!!!😎😁👌")
        else:
            print("No Problem, Let's Try Again 😀")
        break  # Break the loop if the user enters a valid answer
    # Ask the user to enter a valid answer
    print(f"Sorry I Don't Understand {answer}!!🫤  Try Again")
