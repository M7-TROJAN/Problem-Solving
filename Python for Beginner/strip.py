
""" strip() , lstrip() , rstrip"""

# striped white spaces from the end and beginning 
str1 = "    mahmoud    "
print(f"before: {str1}")
str1 = str1.strip()
print(f"after: {str1}\n")


# striped * from the end and beginning

str2 = "*****mahmoud*****"
print(f"before: {str2}")
str2 = str2.strip("*")
print(f"after: {str2}\n")


# striped * from the beginning

str3 = "*****mahmoud*****"
print(f"before: {str3}")
str3 = str3.lstrip("*")
print(f"after: {str3}\n")


# striped * from the end

str4 = "*****mahmoud*****"
print(f"before: {str4}")
str4 = str4.rstrip("*")
print(f"after: {str4}\n")