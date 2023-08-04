""" username project """

# Get the user's name
while True:
    name = input("Enter your name: ").strip()
    # Check if the name is empty
    if not name:
        print("Invalid input. Please enter your name.")
        continue
    # Check if there are more than one spaces in the name
    count = 0
    for i in range(len(name)-1):
        if name[i] == " " and name[i+1] == " ":
            count += 1
    if count > 0:
        print("Invalid input. Please enter your name without extra spaces.")
        continue
    # If the input is valid, break out of the loop
    break

# Convert the name to a username
# Remove extra spaces around name
# Replace spaces with underscores
# Make all letters lowercase
# Add '@m7trojan.com' to the end of the username
username = f"{name.strip().lower().replace(' ', '_')}@m7trojan.com"

# Greet the user
print(f"Hello, {name.title()}!")

# Print the username
print(f"Your username is:\n{username}")
