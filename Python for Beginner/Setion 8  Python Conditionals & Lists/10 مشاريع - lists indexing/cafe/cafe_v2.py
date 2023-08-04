# a dictionary of drinks
drinks = {
    'hot': ['Tea', 'Herbs', 'Hot Cider', 'Coffee', 'Hot Chocolate'],
    'soda': ['Coke', 'Pepsi', 'Fanta', 'Sprite', 'Mirinda'],
    'juice': ['Lemonade', 'Orange Juice', 'Mango Juice', 'Strawberry Juice', 'Apple Juice']
}

# a message to ask for the type of the drink
print("Please choose your drink type from the menu below:")
for i, drink_type in enumerate(drinks.keys()):
    print(f"{i+1}. {drink_type}")

while True:
    try:
        order_index_type = int(input("Enter the number of the drink type you want to order: "))
        if 1 <= order_index_type <= len(drinks.keys()):
            order_index_type -= 1
            print()
            break
        else:
            print("Invalid input, please try again.")
            print()
    except ValueError:
        print("Invalid input, please enter a number.")

# print the menu for the selected drink type
drink_type = list(drinks.keys())[order_index_type]
print(f"Please choose your {drink_type} from the menu below:")
for i, drink in enumerate(drinks[drink_type]):
    print(f"{i+1}. {drink}")

while True:
    try:
        order_index = int(input("Please enter the number of the drink you want to order: "))
        if 1 <= order_index <= len(drinks[drink_type]):
            order_index -= 1
            print()
            break
        else:
            print("Invalid input, please try again.")
            print()
    except ValueError:
        print("Invalid input, please enter a number.")

# print the order
order = drinks[drink_type][order_index]
print('-' * 50)
print('Thanks for choosing M7_TROJAN Café!')
print(f'Please enjoy your time while we get {order} ready for you.')
