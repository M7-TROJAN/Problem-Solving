def main():
    while True:
        try:
            n = int(input("N: "))
            if n > 0:
                break
        except ValueError:
            pass
    mario(n)

# solution 1 by using nested loop
def mario(n):
    for i in range(n):
        for x in range(n):
            print("#", end= "")
        print()


# another solution by using one loop not tow and use print( "string" * n)

# def mario(n):
#     for i in range(n):
#         print("#" * n)
        


main()