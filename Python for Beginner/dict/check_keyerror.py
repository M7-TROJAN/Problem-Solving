"""  check if the key is exist in the dict or no """

phoneBook ={
    "mahmoud" : "01019060452",
    "semsem"  : "01129816608"
}
search = input("search for: ")

# best way use it
if search in phoneBook:
    print("found")
    print(f"name: {search}\nPhone Number: {phoneBook[search]}")
else:
    print("not found")


#..............................................................................

# bad do not use it

# try:
#     if phoneBook[search]:
#         print("found")
#         print(f"name: {search}\nPhone Number: {phoneBook[search]}")
# except KeyError:
#     print("not found")

