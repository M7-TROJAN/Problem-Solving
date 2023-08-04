def main():
    print("\nthis program yo calculate the factorial of a number\n")
    while True:
        try:
            n = int(input("enter the number: "))
            if n < 1:
                raise ValueError
            break
        except ValueError:
            print("invalid value, you must type a numeric value bigger than 0")
    
    result = factorial(n)
    print("the factorial of %d is %d" % (n , result))


def factorial(x):
    if x == 0:
        return 1
    else:
        return x * factorial(x-1)


main()