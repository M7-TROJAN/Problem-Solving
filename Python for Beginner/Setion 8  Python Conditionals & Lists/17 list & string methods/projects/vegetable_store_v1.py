""" vegetables store"""

# list of available vegetables
vegetables = ['broccoli', 'eggplant', 'carrot', 'cabbage','cucumber', 'potato', 'garlic', 'pepper']

# greeting
print("Welcome to M7Trojan Vegetables!")

# get the order from user
order = input("Enter the vegetable you want to get: ")

# join vegetable names with commas and 'and'
str_vegetables = ", ".join(vegetables[:-1]).capitalize() + ", and " + vegetables[-1].capitalize()

print("=" * 35)

# check if the order is in the vegetables list
if order.lower() in vegetables:
    
    # get the amount of the vegetable ordered
    while True:
        try:
            amount = float(input("Enter the amount in kg: "))
            if amount > 0:
                print(f"We will get you {amount:.1f} kg of {order.capitalize()} very soon.")
                break
        except ValueError:
            print("Invalid input. Please enter a numeric value.")
else:
    print(f"Sorry, we only have {str_vegetables}.")
