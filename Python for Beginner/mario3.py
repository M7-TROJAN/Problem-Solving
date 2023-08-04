def main():
    while True:
        try:
            n = int(input("N: "))
            if n > 0:
                break
        except ValueError:
            pass
    mario(n)

def mario(n):
    for i in range(n):
        for x in range(i+1):
            print("#", end= "")
        print()
        

    


main()