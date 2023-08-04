# Import the random module
import random

# Set the company domain name
company_domain = "m7trogan"

# Prompt the user to enter their first and last name
fname = input("Enter Your First Name: ").strip().replace(" ", "").capitalize()
lname = input("Enter Your Last name: ").strip().replace(" ", "").capitalize()

# Generate a random ID number for the user
id = random.randint(1, 1000)

# Use a loop to repeatedly prompt the user for an email address until a valid one is entered
while True:
    try:
        # Prompt the user to enter their email address and remove any leading/trailing white space
        user_email = input("Enter your email address: ").strip().replace(" ", "")
        # Find the position of the '@' symbol in the email address
        index_of_at = user_email.index('@')
        # Combine the user's email address up to the '@' symbol with the ID number and company domain name to create the company email address
        company_email = user_email[:index_of_at+1] + str(id) + company_domain
        # Exit the loop since a valid email address was entered
        break
    except ValueError:
        # Handle the case where the '@' symbol is not found in the email address
        print("Invalid email address. Please try again.")

# Greet the user and print their ID number and company email address
print("=" * 40)
print(f"Welcome {fname} {lname}")
print(f"Your ID Is: {id}")
print(f"Your Company Email Is:\n{company_email}")
