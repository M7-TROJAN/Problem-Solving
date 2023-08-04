
"""csv files in python"""

# import csv module
import csv

#  a function to force user to type just an integer value
def get_int():
    """ a function to get the age """

    while True:
        try:
            A = int(input("age: "))
            if A > 0:
                break
        except ValueError:
            print("invalid input age must be a numeric value")
    return A


#the driver code

# first create a csv file
with open("phoneBook.csv" , "w" , newline="" , encoding= "utf-8") as file:
    # second make the hed line row
    csv.writer(file).writerow(["Name" , "Number" , "Age" , "Country"])
    for i in range(6):
        # third get data from user name , number , age and country
        name = input("name: ")
        number = input("number: ")
        age = get_int()  # age must ba a numeric value and bigger than 0
        country = input("country: ")
        # forth put the data to the file as a row
        csv.writer(file).writerow([name,number , age , country])


# not:
# By opening the file with newline='', the writer object will not add any extra newlines when writing to the file.