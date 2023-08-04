
""" phone book example """

# create empty dict
phoneBook = {}

# add data to phoneBook 
print("add data to the phoneBook")
while True:
    name = input("name: ")
    number = input("phone number: ")
    phoneBook[name] = number

    while True:
        check = input("again(y/n)?: ")
        if check in ['n' , 'y' , 'N' , 'Y']:
            break
    if check in ['n' , 'N']:
        break

# search in the phoneBook
search = input("search for: ")
if search in phoneBook:
    print("found")
    print(phoneBook[search])
else:
    print("not found ")