def main():
    """The Main Function"""

    while True:
        # ask the user which conversion they would like to perform
        choice = get_conversion_choice()

        # perform the appropriate conversion
        if choice == 'm_cm':
            perform_meter_to_centimeter_conversion()
        elif choice == 'cm_m':
            perform_centimeter_to_meter_conversion()
        elif choice == 'kg_g':
            perform_kilogram_to_gram_conversion()
        elif choice == 'g_kg':
            perform_gram_to_kilogram_conversion()
        else:
            print("Invalid choice, please try again.")

        # ask the user if He would like to perform another conversion
        response = input("Would you like to perform another conversion? (y/n): ")
        if response.lower() != 'y':
            break


def get_conversion_choice():
    """Prompt the user to select a type of conversion."""
    print("Which conversion would you like to perform?")
    print("1. Meters to centimeters")
    print("2. Centimeters to meters")
    print("3. Kilograms to grams")
    print("4. Grams to kilograms")
    while True:
        try:
            choice = int(input("Enter your choice (1-4): "))
            if choice not in [1, 2, 3, 4]:
                raise ValueError
            break
        except ValueError:
            print("Invalid input, please try again.")
    if choice == 1:
        return 'm_cm'
    elif choice == 2:
        return 'cm_m'
    elif choice == 3:
        return 'kg_g'
    else:
        return 'g_kg'


def perform_meter_to_centimeter_conversion():
    """Perform a conversion from meters to centimeters."""
    while True:
        try:
            meters = float(input("Enter the length in meters: "))
            break
        except ValueError:
            print("Invalid input, please try again.")
    centimeters = meters * 100
    print(f"{meters:.2f} meters is equal to {centimeters:.2f} centimeters.")


def perform_centimeter_to_meter_conversion():
    """Perform a conversion from centimeters to meters."""
    while True:
        try:
            centimeters = float(input("Enter the length in centimeters: "))
            break
        except ValueError:
            print("Invalid input, please try again.")
    meters = centimeters / 100
    print(f"{centimeters:.2f} centimeters is equal to {meters:.2f} meters.")


def perform_kilogram_to_gram_conversion():
    """Perform a conversion from kilograms to grams."""
    while True:
        try:
            kilograms = float(input("Enter the weight in kilograms: "))
            break
        except ValueError:
            print("Invalid input, please try again.")
    grams = kilograms * 1000
    print(f"{kilograms:.2f} kilograms is equal to {grams:.2f} grams.")


def perform_gram_to_kilogram_conversion():
    """Perform a conversion from grams to kilograms."""
    while True:
        try:
            grams = float(input("Enter the weight in grams: "))
            break
        except ValueError:
            print("Invalid input, please try again.")
    kilograms = grams/1000
    print(f"{grams:.2f} grams is equal to {kilograms:.2f} kilograms.")


# Code Starts From Here
main()
