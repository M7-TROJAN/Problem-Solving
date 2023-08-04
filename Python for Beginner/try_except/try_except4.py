# Finally Keyword in Python
# Python provides a keyword finally, which is always executed after the try and except blocks.
# The final block always executes after normal termination of try block or after try block terminates due to some exceptions.


# syntax:

"""
try:
    # Some Code
except:
    # Executed if error in the
    # try block
else:
    # execute if no exception
finally:
    # Some code .....(always executed)

"""

# example:


# Python program to demonstrate finally

# No exception Exception raised in try block
try:
    k = 5//0 # raises divide by zero exception.
    print(k)
    
# handles zerodivision exception
except ZeroDivisionError:
    print("Can't divide by zero")
        
finally:
    # this block is always executed
    # regardless of exception generation.
    print('This is always executed')


# Output:

# Can't divide by zero
# This is always executed