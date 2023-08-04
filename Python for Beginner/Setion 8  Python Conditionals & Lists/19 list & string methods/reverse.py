
name = input("mahmoud")

# convert string to list
name_list = list(name)

# reverse the list 
name_list.reverse()

# make a string from a reversed list by using join() method
reversed_name = "".join(name_list)

# print reversed name
print(reversed_name)