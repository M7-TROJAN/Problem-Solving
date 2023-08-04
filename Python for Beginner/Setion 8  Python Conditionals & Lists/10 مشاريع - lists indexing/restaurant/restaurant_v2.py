# a list of pizzas
pizzas = [
    'Margherita',
    'Pepperoni',
    'Super Supreme',
    'Hawaiian',
    'Meat Lovers',
    'Cheese Lovers'
]

# welcome message
print("Welcome to M7_TROJAN Pizza 🍕")

# display the available pizzas
print("Please choose a pizza from the menu below:")
for i, pizza in enumerate(pizzas):
    print(f"{i+1}. {pizza}")
print()

# get the user's order
while True:
    try:
        order = int(input("Enter the number of the pizza you want to order: "))
        if 0 < order <= len(pizzas):
            break
        else:
            print("Invalid input, please try again.")
            print()
    except ValueError:
        print("Invalid input, please enter a number.")
        print()

# ask the user if they want to add anything else
print()
response = input("Would you like to add anything else to your order? (y/n): ")
print()
if response.lower() == 'y':
    print("Sorry, we only serve pizza at this time.")
else:
    print("Thank you for your order! Your pizza will be ready shortly.")
    print()
    # calculate the total price
    total_price = 10.99
    print(f"Your total price is: ${total_price:.2f}") # format the price to 2 decimal places
    print("Enjoy your meal!")
