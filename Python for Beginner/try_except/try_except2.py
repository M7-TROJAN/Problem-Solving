
# example:
# There is an exception so only except clause will run.

# Python code to illustrate working of try()
def divide(x, y):
    try:
        # Floor Division : Gives only Fractional Part as Answer
        result = x // y
        print("Yeah ! Your answer is :", result)
    except ZeroDivisionError:
        print("Sorry ! You are dividing by zero ")

# Look at parameters and note the working of Program
divide(3, 0)


# output will be -->  (Sorry ! You are dividing by zero)