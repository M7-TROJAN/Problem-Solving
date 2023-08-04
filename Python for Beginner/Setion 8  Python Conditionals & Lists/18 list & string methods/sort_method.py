""" sort() method"""

# Definition and Usage
    # The sort() method sorts the list ascending by default.
    # You can also make a function to decide the sorting criteria(s).

# Syntax:
#   list.sort(reverse=True|False, key=myFunc)

# Parameter Values
    # Parameter	         Description
    # reverse	         Optional. reverse=True will sort the list descending. Default is reverse=False
    # key	             Optional. A function to specify the sorting criteria(s)

# ascending   => من الصغير للكبير 
# descending  => من الكبير للصغير

# ......................................................................................

my_list = [10,9,8,6,7,1,3,2,4,5]

print(f"after Sorting:\n{my_list}") # [10,9,8,6,7,1,3,2,4,5]
my_list.sort()
print(f"Before Sorting:\n{my_list}") # [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

print("===============================\n")

# ......................................................................................


# Example
# Sort the list descending:

cars = ['Ford', 'BMW', 'Volvo']

cars.sort(reverse=True) # من الكبير للصغير
print(cars,"\n") # ['Volvo', 'Ford', 'BMW']

# ......................................................................................