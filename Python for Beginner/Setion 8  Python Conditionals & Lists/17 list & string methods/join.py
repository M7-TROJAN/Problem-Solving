# join()
""" Definition and Usage """
    # The join() method takes all items in an iterable and joins them into one string.
    # A string must be specified as the separator.

# Syntax: => string.join(iterable)

# Parameter	         Description
# iterable	          Required. Any iterable object where all the returned values are strings

# ...................................................................................

# examples:
myTuple = ("John", "Peter", "Vicky")

x = "#".join(myTuple)

print(x) # John#Peter#Vicky

# ...................................................................................

my_list = ["Mahmoud" , "Mohamed", "Abdalaziz", "Mousa", "Mesbah", "Mattar"]

string = " ".join(my_list)

print(string) # Mahmoud Mohamed Abdalaziz Mousa Mesbah Mattar

# ...................................................................................

myDict = {"name": "John", "country": "Norway"}
mySeparator = "TEST"

x = mySeparator.join(myDict)

print(x) # nameTESTcountry