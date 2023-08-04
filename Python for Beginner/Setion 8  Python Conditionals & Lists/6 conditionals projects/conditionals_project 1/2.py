import csv

# Prompt the user for username and password
username = input("Enter User Name: ").strip().lower()
password = input("Enter Password: ").strip()

# Open the CSV file using a context manager to ensure proper file handling
with open("accounts.csv", "r", encoding="utf-8", newline="") as file:
    # Use the csv module to read the file
    reader = csv.reader(file)
    # Skip the header row
    next(reader)

    # Loop through each row in the CSV file
    for row in reader:
        # Check if the username and password match
        if row[0] == username and row[1] == password:
            # Print a welcome message if the credentials are correct
            print(f"Welcome {username}")
            break # Exit the loop if the credentials are correct
    else:
        # Print an error message if the loop completes without finding a match
        print("Invalid username or password")