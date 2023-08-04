import random

# Get user input for name, company name, and birth year
name = input("Enter Your Name: ").strip().title()
company_name = input("Enter Your Company Name: ").strip().title()
birth_year = int(input("Enter Your Birth Year: "))

# Generate user ID based on company name, last two letters of name, birth year, and a random number
id = company_name[:3].replace(" ","") + "-" + name[-2:] + str(birth_year) + str(random.randint(1, 9))

# Loop until a valid email address is entered
while True:
    try:
        # Get user input for email address
        email = input("Enter Your Email: ").strip().lower()
        # Find the index of the '@' symbol in the email address
        index_of_at = email.index("@")
        # Combine the user's email address up to the '@' symbol with the company name and '.com' to create the company email address
        company_email = email[:index_of_at + 1] + company_name.replace(" ", "") + ".com"
        break
    except ValueError:
        # Handle the case where the '@' symbol is not found in the email address
        print("Invalid email address. Please try again.")

# Greet the user and print their ID and email address
print("=" * 30)
print(f"Hello, {name}!\nWelcome To {company_name}!!")
print("=" * 30)
print(f"Your Id Is {id}")
print(f"Your Email Is {company_email}")
