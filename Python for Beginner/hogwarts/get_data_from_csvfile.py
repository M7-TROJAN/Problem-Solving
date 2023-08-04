

# steps:
    # 1 score = 0
    # 2 opec csv file 
    # 3 read house column        column ->  عمود
    # 4 add score
    # 5 print score of each house


import csv

# a dict for store the scores of houses
Houses = {
    "Gryffindor" : 0,
    "Ravenclaw"  : 0,
    "Slytherin"  : 0,
    "Hufflepuff" : 0
}

# open hogwarts.csv file to read and get the data
with open("hogwarts.csv", "r" , encoding="utf-8" ) as f:
    reader = csv.reader(f)        # reader returns the data as lists each list represents a row
    # skip the head line row
    next(reader)
    for row in reader:
        Houses[row[1]] +=1


for key , val in Houses.items():
    print(f"{key} : {val}")



# get the height value 
max_key = None
max_val = float("-inf")   # -inf means negative infinity

# check the height value of scores
for key, val in Houses.items():
    if val > max_val:
        max_key = key
        max_val = val

print("the key with the highest value is:",max_key)
print("the highest value is:",max_val)




# another way by using csv.DictReader() method

import csv

# a dict for store the scores of houses
Houses = {
    "Gryffindor" : 0,
    "Ravenclaw"  : 0,
    "Slytherin"  : 0,
    "Hufflepuff" : 0
}

# open hogwarts.csv file to read and get the data
with open("hogwarts.csv", "r" , encoding="utf-8" ) as f:
    reader = csv.DictReader(f)        # reader returns the data as lists each list represents a row

    for row in reader:
        Houses[row["House"]] +=1


for key , val in Houses.items():
    print(f"{key} : {val}")



# get the height value 
max_key = None
max_val = float("-inf")   # -inf means negative infinity

# check the height value of scores
for key, val in Houses.items():
    if val > max_val:
        max_key = key
        max_val = val

print("the key with the highest value is:",max_key)
print("the highest value is:",max_val)
