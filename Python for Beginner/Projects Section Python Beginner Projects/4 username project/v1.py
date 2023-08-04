""" username project """

# get name
while True:
    name = input("Enter Your Name: ").strip()
    # Check if there are more than one spaces in the name
    count = 0
    for i in name:
        if i == " ":
            count+=1
    if count > 1:
        print("It's more spaces in your name")
    else:
        break

# convert name to username
# remove extra spaces around name
# replace spaces with underscore
# make all letters small
# add '@m7trojan.com' to the end of the username
userName = name.lower().replace(" " , "_") + "@m7trojan.com"

# greet user
print(f"Hello {name.title()}")

# print username
print(f"Your Username Is:\n{userName}")