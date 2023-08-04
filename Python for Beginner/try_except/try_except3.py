""" 
Else Clause:
In python, you can also use the else clause on the try-except block which must be present after all the except clauses.
The code enters the else block only if the try clause does not raise an exception.

"""

# stntax 
""" 
try:
    # Some Code
except:
    # Executed if error in the
    # try block
else:
    # execute if no exception
"""

# example:


# Program to depict else clause with try-except

# Function which returns a/b
def AbyB(a , b):
    try:
        c = ((a+b) // (a-b))
    except ZeroDivisionError:
        print ("a/b result in 0")
    else:
        print (c)

# Driver program to test above function
AbyB(2.0, 3.0)
AbyB(3.0, 3.0)