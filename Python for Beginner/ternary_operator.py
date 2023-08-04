
"""In Python, you can use the ternary operator to write a concise if-else statement in a single line of code."""

# The syntax of the ternary operator is:

# expression_if_true if condition else expression_if_false

# Here is an example of how to use the ternary operator:

# .....................................................................................

# examples:

# Example 1: Using the ternary operator to return a value based on a condition
X= 5
Y = 10
max_num = X if X > Y else Y
print(max_num)  # Output: 10
# .....................................................................................

# Example 2: Using the ternary operator to print a message based on a condition
num = 7
print("Even" if num % 2 == 0 else "Odd")  # Output: Odd
# .....................................................................................

# Example 3: Using the ternary operator to print a message based on a condition
name = "mahmoud"
name2 = name

print("same" if name == name2 else "different") # Output: same
# .....................................................................................

# Example 4: Using the ternary operator to return a message based on a condition

def even_or_odd(n):
    """function to determine whether a number is even or odd"""

    # if n%2 equals to zero, return "even" else return "odd"
    return "even" if n%2 == 0 else  "odd"

# get user input
n = int(input("Enter A Number: "))

# call even_or_odd function and store result in variable x
x = even_or_odd(n)

# print the result
print(x)
