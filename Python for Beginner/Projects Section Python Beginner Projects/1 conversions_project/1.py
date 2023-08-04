""" baaaaaaaaaaaaaaaaaaaaaad
    conversions project """

def main():
    """ The Main Fun """
    # ask the user about the process
    choice = start()
    
    # cheek the user choice
    if choice == 2:
        gram_convert()
    else:
        meter_convert()
    

def start():
    """The Opening Message"""

    print(
    """          chose the Number of process
    ============================================
    (1) to conversion from m to cm or vice versa
    (2) to conversion from kg to g or vice versa
    ============================================"""
    )
    # take the process number from user
    while True:
        try:
            chose = int(input("Enter Your Choice: "))
            if chose not in [1,2]:
                raise ValueError
            break
        except ValueError:
            print("Error Invalid Input")
    return chose


def gram_convert():
    print("To convert From G to KG TYpe 1")
    print("To convert From KG to G TYpe 2")
    while True:
        try:
            convert = int(input("Enter YOur Choice: "))
            if convert not in [1,2]:
                raise ValueError
            break
        except ValueError:
            print("Invalid Input")
    if convert == 1:
        while True:
            try:
                g = int(input("Enter The Weight in Gram: "))
                break
            except ValueError:
                print("Invalid Input")
    
        print(f"{g} Gram is {g/1000:,} Kg")
    
    elif convert == 2:
        while True:
            try:
                kg = int(input("Enter The Weight in Kilo Gram: "))
                break
            except ValueError:
                print("Invalid Input")
    
        print(f"{kg} KiloGram is {kg*1000:,} Gram")


def meter_convert():
    print("To convert From Centimeter to Meter TYpe 1")
    print("To convert From Meter to Centimeter TYpe 2")
    while True:
        try:
            convert = int(input("Enter YOur Choice: "))
            if convert not in [1,2]:
                raise ValueError
            break
        except ValueError:
            print("Invalid Input")
    if convert == 1:
        while True:
            try:
                cm = int(input("Enter The height in Centimeter: "))
                break
            except ValueError:
                print("Invalid Input")
    
        print(f"{cm} Centimeter is {cm/100:,} Meter")
    
    elif convert == 2:
        while True:
            try:
                m = int(input("Enter The height in meter: "))
                break
            except ValueError:
                print("Invalid Input")
    
        print(f"{m} Meter: is {m*100:,} Centimeter:")


main()
