
# Prompt the user to enter their full name and strip any leading/trailing white space
full_name = input("Enter Your Full Name: ").strip().title()

# Find the index of the first space in the full name
index_of_first_space = full_name.index(" ")

# Extract the first name from the full name by slicing up to the index of the first space
first_name = full_name[:index_of_first_space]

# Greet the user using their first name and print a welcome message
print("=" * 30)
print(f"hello {first_name} !\nWelcome At M7TROJAN!!!")


# .............................................................................

# version 2

# Prompt the user to enter their full name and strip any leading/trailing white space
full_name = input("Enter Your Full Name: ").strip().title()

# Find the index of the first space in the full name
try:
    space_index = full_name.index(" ")
except ValueError:
    print("Invalid name format. Please enter your full name with a space in between.")
    exit()

# Extract the first name from the full name by slicing up to the index of the first space
first_name = full_name[:space_index]

# Greet the user using their first name and print a welcome message
print(f"Hello {first_name}!\nWelcome to M7TROJAN!!!")
