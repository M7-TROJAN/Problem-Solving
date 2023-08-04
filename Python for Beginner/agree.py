def main():
    answer = input("are you agree (y/n)?: ")
    while answer.lower() not in ['y', 'n']:
        print("invalid input")
        answer = input("are you agree (y/n)?: ")
    check(answer)

def check(x):
    if x.lower() == 'y':
        print("you are agree")
    elif x.lower() == 'n':
        print("you are not agree")


main()

#.....................................................................

# another solution by using lower() function with input() function

# def main():
#     answer = input("are you agree (y/n)?: ").lower()
#     while answer not in ['y', 'n']:
#         print("invalid input")
#         answer = input("are you agree (y/n)?: ").lower()
#     check(answer)

# def check(x):
#     if x == 'y':
#         print("you are agree")
#     elif x == 'n':
#         print("you are not agree")


# main()