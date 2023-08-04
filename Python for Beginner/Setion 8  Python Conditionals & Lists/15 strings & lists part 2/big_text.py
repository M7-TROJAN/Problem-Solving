Text ="""
A computer is a digital electronic machine that can be programmed to carry out
sequences of arithmetic or logical operations (computation) automatically.
Modern computers can perform generic sets of operations known as programs.
These programs enable computers to perform a wide range of tasks. A computer
system is a "complete" computer that includes the hardware, operating system (main software),
and peripheral equipment needed and used for "full" operation.
This term may also refer to a group of computers that are linked and function
together, such as a computer network or computer cluster.
"""

list_of_words = Text.split()

for i in list_of_words:
    print(i,end=" ")