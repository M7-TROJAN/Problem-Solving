# You can reverse a string in Python by using slicing. Here's an example:

string = "Hello, world"
reversed_string = string[::-1]
print(reversed_string) 

# output:
    # dlrow ,olleH



explain = """In Python, string[::-1] is used to reverse a string.

The string is the original string that you want to reverse. The square brackets [] are used for slicing, which allows you to select a specific range of characters from a string.

The :: in the square brackets are slice notation, which consists of three parts: start:stop:step.

start is the index of the first character in the range (default is 0).
stop is the index of the last character in the range (default is the end of the string).
step is the increment for the index (default is 1).
In the case of string[::-1], the step value is -1, which means it will reverse the string. The start and stop values are not specified, so the entire string is selected.

For example, if you have a string "Hello, World!", using string[::-1] will return "!dlroW ,olleH"."""