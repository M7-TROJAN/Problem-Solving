
# syntax:
""" 
    try:
        # Some Code
    except:
        # Executed if error in the try block

"""

# example1: No exception, so the try clause will run.

# Python code to illustrate working of try()
def divide(x, y):
	try:
		# Floor Division : Gives only Fractional Part as Answer
		result = x // y
		print("Yeah ! Your answer is :", result)
	except ZeroDivisionError:
		print("Sorry ! You are dividing by zero ")

# Look at parameters and note the working of Program
divide(3, 2)


# Output will be -->  ('Yeah ! Your answer is :', 1)