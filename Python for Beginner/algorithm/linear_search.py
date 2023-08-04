
""" liner search method """


#method1

my_list = [1, 2, 3, "mahmoud", "mattar", 1998, "01019060452"]

search = input("search for: ")

if search in str(my_list):
    print("found")
else:
    print("not found")


#.........................................................................

# method 2

# def main():
#     """the driver code"""

#     my_list = [1, 2, 3, "mahmoud", "mattar", 1998, "01019060452"]
#     search = input("search for: ")

#     if liner_search( my_list,search) is True:
#         print("found")
#     else:
#         print("not found")


# def liner_search(my_list,search):
#     """function to search for an element into list"""

#     for i in my_list:
#         if search.lower() == str(i):
#             return True
#     return False


# main()

#....................................................................

# my_list = [1, 2, 3, "mahmoud", "mattar", 1998, "01019060452"]

# search = input("search for: ")

# for i in range(len(my_list)):
#     if search == str(my_list[i]):
#         print(f"found in index number {i}")
