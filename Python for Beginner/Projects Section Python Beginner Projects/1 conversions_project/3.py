METER_TO_CENTIMETER_FACTOR = 100
KILOGRAM_TO_GRAM_FACTOR = 1000

def get_conversion_choice():
    """Prompt the user to select a type of conversion."""
    options = {
        '1': perform_meter_to_centimeter_conversion,
        '2': perform_centimeter_to_meter_conversion,
        '3': perform_kilogram_to_gram_conversion,
        '4': perform_gram_to_kilogram_conversion,
    }
    print("Which conversion would you like to perform?")
    print("1. Meters to centimeters")
    print("2. Centimeters to meters")
    print("3. Kilograms to grams")
    print("4. Grams to kilograms")
    while True:
        choice = input("Enter your choice (1-4): ")
        if choice not in options:
            print("Invalid input, please try again.")
            continue
        return options[choice]

def perform_meter_to_centimeter_conversion():
    """Perform a conversion from meters to centimeters."""
    while True:
        try:
            meters = float(input("Enter the length in meters: "))
            if meters < 0:
                raise ValueError
            break
        except ValueError:
            print("Invalid input, please try again.")
    centimeters = meters * METER_TO_CENTIMETER_FACTOR
    print(f"{meters:.2f} meters is equal to {centimeters:.2f} centimeters.")

def perform_centimeter_to_meter_conversion():
    """Perform a conversion from centimeters to meters."""
    while True:
        try:
            centimeters = float(input("Enter the length in centimeters: "))
            if centimeters < 0:
                raise ValueError
            break
        except ValueError:
            print("Invalid input, please try again.")
    meters = centimeters / METER_TO_CENTIMETER_FACTOR
    print(f"{centimeters:.2f} centimeters is equal to {meters:.2f} meters.")

def perform_kilogram_to_gram_conversion():
    """Perform a conversion from kilograms to grams."""
    while True:
        try:
            kilograms = float(input("Enter the weight in kilograms: "))
            if kilograms < 0:
                raise ValueError
            break
        except ValueError:
            print("Invalid input, please try again.")
    grams = kilograms * KILOGRAM_TO_GRAM_FACTOR
    print(f"{kilograms:.2f} kilograms is equal to {grams:.2f} grams.")

def perform_gram_to_kilogram_conversion():
    """Perform a conversion from grams to kilograms."""
    while True:
        try:
            grams = float(input("Enter the weight in grams: "))
            if grams < 0:
                raise ValueError
            break
        except ValueError:
            print("Invalid input, please try again.")
    kilograms = grams / KILOGRAM_TO_GRAM_FACTOR
    print(f"{grams:.2f} grams is equal to {kilograms:.2f} kilograms.")