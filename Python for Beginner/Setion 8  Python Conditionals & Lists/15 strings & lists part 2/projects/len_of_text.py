# text
"""A computer is a digital electronic machine that
can be programmed to carry out sequences of arithmetic or
logical operations automatically"""

# get the text
text = input("Enter Your Text: ")

# remove all spaces
new_text = text.replace(" ", "")
# get the number of characters
print("Number of characters with spaces: ", len(text))
print("Number of characters without spaces: ", len(new_text))