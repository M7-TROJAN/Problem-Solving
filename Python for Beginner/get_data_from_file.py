

with open("myfile.txt" , "r") as file:
    s = file.read() # to read all of content
    print(s)

#...........................................................................................


with open("myfile.txt" , "r") as file:
    s = file.readline()  # to read one line 
    print(s)

# ..............................................................................................


# to read line by line using next() function
with open("myfile.txt" , "r") as file:
    while True:
        try:
            s = next(file)  
            print(s , end="")
        except StopIteration:
            break
print()

# ..............................................................................................

# read line by line by using for loop
with open("myfile.txt" , "r") as file:
    for line in file:
        print(line , end="")

