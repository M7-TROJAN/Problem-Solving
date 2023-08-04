
# check if the number is even or odd

def main():
    while True:
        try:
            number = int(input("enter a number: "))
            break
        except ValueError:
            pass
    check(number)

def check(num):
    if num % 2 == 0:
        print(f"{num} is even")
        return True
    print(f"{num} is odd")
    return False

main()