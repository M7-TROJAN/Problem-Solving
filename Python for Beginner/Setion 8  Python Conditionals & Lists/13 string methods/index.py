
# index()
    # Searches the string for a specified value and returns the position of where it was found
# syntax:
    # string.index(specified value)
# return:
    # int the position of where specified value was found


# example:

# Set the company domain name
company_domain = "m7trojan.com"

# Use a loop to repeatedly prompt the user for an email address until a valid one is entered
while True:
    try:
        # Prompt the user to enter their email address
        user_email = input("Enter your email address: ")
        # Find the position of the '@' symbol in the email address
        index_of_at = user_email.index('@')
        # Combine the user's email address up to the '@' symbol with the company domain name to create the company email address
        company_email = user_email[:index_of_at+1] + company_domain
        # Exit the loop since a valid email address was entered
        break
    except ValueError:
        # Handle the case where the '@' symbol is not found in the email address
        print("Invalid email address. Please try again.")

# Print the company email address
print("=" * 40)
print(f"Your Company Email Is:\n{company_email}")
