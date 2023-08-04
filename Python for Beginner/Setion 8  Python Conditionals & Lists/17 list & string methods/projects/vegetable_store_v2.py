""" vegetables store"""

# list of available vegetables
vegetables = ['broccoli', 'eggplant', 'carrot', 'cabbage','cucumber', 'potato', 'garlic', 'pepper']

# greeting
print("Welcome to M7Trojan Vegetables!")

# get the order from user
while True:
    order = input("Enter the vegetable you want to get: ")
    if order.lower() in vegetables:
        break
    else:
        print(f"Sorry, we only have {', '.join(vegetables[:-1])}, and {vegetables[-1]}.")

# get the amount of vegetable from user
while True:
    try:
        amount = float(input(f"Enter the amount of {order} you want (in kg): "))
        if amount > 0:
            break
        else:
            print("Invalid input. Amount must be greater than zero.")
    except ValueError:
        print("Invalid input. Please enter a numeric value.")

# display order confirmation
print("=" * 35)
print(f"We will get you {amount:.1f} kg of {order} very soon. Thank you for your order!")
