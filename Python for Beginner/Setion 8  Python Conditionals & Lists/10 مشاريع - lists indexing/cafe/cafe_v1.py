# Create a list of drink types, which each drink type contains a list of drinks
drinks = [
# hot drinks
['Tea', 'Herbs', 'Hot Cider', 'Coffee', 'Hot Chocolate'],
# soda
['Coke', 'Pepsi', 'Fanta', 'Sprite', 'Mirinda'],
# juices
['Lemonade', 'Orange Juice', 'Mango Juice','Strawberry Juice', 'Apple Juice']
]

# Ask the user to choose the drink type they want
print("Please choose your Drink Kind from the menu below:")
for i , drink in enumerate(["hot drinks" , "soda" , "juices"]):
    print(f"{i+1}. {drink}")

# Loop until the user enters a valid drink type
while True:
    try:
        order_index_type = int(input("Enter the number of the Drink Kind you want to order: "))
        if 0 < order_index_type <= 3:
            order_index_type-=1 # convert to 0-based index
            print()
            break
        else:
            print("Invalid input, please try again.")
            print()
    except ValueError:
        print("Invalid input, please enter a number.")

# Ask the user to choose the drink they want from the selected drink type
print("Please choose your Drink from the menu below:")
for i , drink in enumerate(drinks[order_index_type]):
    print(f"{i+1}. {drink}")

# Loop until the user enters a valid drink index
while True:
    try:
        order_index = int(input("Please, Enter the number of the drink you want to order: "))
        if 0 < order_index <= len(drinks[order_index_type]):
            order_index-=1 # convert to 0-based index
            print()
            break
        else:
            print("Invalid input, please try again.")
            print()
    except ValueError:
        print("Invalid input, please enter a number.")

# Print the order summary
print('-' * 50)
order = drinks[order_index_type][order_index]
print('Thanks for choosing M7_TROJAN Café!')
print(f'Please, Enjoy your time\nWhile we get {order} ready for you.')
