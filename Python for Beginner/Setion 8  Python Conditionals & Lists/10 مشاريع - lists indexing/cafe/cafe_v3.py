# a dictionary of drinks
drinks_menu = {
    'hot': ['Tea', 'Herbs', 'Hot Cider', 'Coffee', 'Hot Chocolate'],
    'soda': ['Coke', 'Pepsi', 'Fanta', 'Sprite', 'Mirinda'],
    'juice': ['Lemonade', 'Orange Juice', 'Mango Juice', 'Strawberry Juice', 'Apple Juice']
}

# function to get user input
def get_user_input(prompt, valid_range):
    while True:
        try:
            user_input = int(input(prompt))
            if user_input in valid_range:
                return user_input
            else:
                print(f"Invalid input, please enter a number between {valid_range[0]} and {valid_range[-1]}")
                print()
        except ValueError:
            print("Invalid input, please enter a number.")
            print()

# print the menu of drink types
print("Please choose your drink type from the menu below:")
for index, drink_type in enumerate(drinks_menu.keys()):
    print(f"{index+1}. {drink_type.capitalize()}")

# get the user's drink type selection
valid_range = range(1, len(drinks_menu.keys())+1)
order_index_type = get_user_input("Enter the number of the drink type you want to order: ", valid_range)
drink_type = list(drinks_menu.keys())[order_index_type-1]

# print the menu of drinks for the selected type
print(f"Please choose your {drink_type} from the menu below:")
for index, drink in enumerate(drinks_menu[drink_type]):
    print(f"{index+1}. {drink}")

# get the user's drink selection
valid_range = range(1, len(drinks_menu[drink_type])+1)
order_index = get_user_input("Please enter the number of the drink you want to order: ", valid_range)

# print the order confirmation
order = drinks_menu[drink_type][order_index-1]
print('-' * 50)
print('Thanks for choosing M7_TROJAN Café!')
print(f'Please enjoy your time while we get {order} ready for you.')
