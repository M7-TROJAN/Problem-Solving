# Definition and Usage
    # The split() method splits a string into a list.
    # You can specify the separator, default separator is any whitespace.

# Note: When max split is specified, the list will contain the specified number of elements plus one.

# Syntax:
    # string.split(separator, maxsplit)

# Parameter Values
    # separator	Optional. Specifies the separator to use when splitting the string. By default any whitespace is a separator
    # maxsplit	Optional. Specifies how many splits to do. Default value is -1, which is "all occurrences"

# examples:

txt = "hello, my name is Peter, I am 26 years old"

x = txt.split(", ")

print(x,"\n") # ['hello', 'my name is Peter', 'I am 26 years old']



txt = "apple#banana#cherry#orange"

x = txt.split("#")

print(x, "\n") # ['apple', 'banana', 'cherry', 'orange']



txt = "apple#banana#cherry#orange"

# setting the maxsplit parameter to 1, will return a list with 2 elements!
x = txt.split("#", 1)

print(x) # ['apple', 'banana#cherry#orange']