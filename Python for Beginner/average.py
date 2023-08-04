

#method1:

print("program to Calculate the Average")
print("the program will be stop when your input is 0")
scores = []

while True:
    try:
        n = int(input("type a number: "))
    except ValueError:
        print("invalid input. your input should ba a numeric value")
    if n == 0:
        break
    scores.append(n)
print(f"the average is {( sum(scores) / len(scores) )}")


#..........................................................................................

#method2:

# print("program to Calculate the Average")
# print("the program will be stop when your input is 0")
# scores = []

# while True:
#     try:
#         n = int(input("type a number: "))
#     except ValueError:
#         print("invalid input. your input should ba a numeric value")
#     if n == 0:
#         break
#     scores += [n]
# print(f"the average is {( sum(scores) / len(scores) )}")


#..........................................................................................

#method3:

# print("program to Calculate the Average")
# print("the program will be stop when your input is 0")
# scores = []

# while True:
#     try:
#         n = int(input("type a number: "))
#     except ValueError:
#         print("invalid input. your input should ba a numeric value")
#     if n == 0:
#         break
#     scores.append(n)

# res = 0
# for i in scores:
#     res += i

# print("average is %.2f" % (res / len(scores)))

#..........................................................................................


# another way 

# def main():
#     print("""\nHello to the calculate average program 
# enter the numbers and i wil return it's average to you
# remember the input process will stop when you type the number Zero\n""")
    
#     scores = []
#     while True:
#         try:
#             n = float(input("type the number: "))
#         except ValueError:
#             print("invalid input, you should type numeric value")
#             pass
#         if n < 1:
#             break
#         scores += [n]
    
#     print("the average is --> %.2f" % (sum(scores) / len(scores)))
            


# main()
