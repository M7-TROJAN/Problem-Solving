# a list of pizzas
pizzas = [
    'Margherita',
    'Pepperoni',
    'Super Supreme',
    'Hawaiian',
    'Meat Lovers',
    'Cheese Lovers'
]
# greeting user
print("Welcome To M7_TROJAN Pizza 🍕")

# a message to ask the user for the pizza
print("Please, Enter the number of the pizza you want to order")
# print kinds of pizza
for i, pizza in enumerate(pizzas):
    print(f"{i+1}. {pizza}.")

# get order from user
while True:
    try:
        order = int(input())
        if 0 < order <= len(pizzas):
            break
        else:
            print("Invalid Input")
            print("Please, Enter the number of the pizza you want to order: ")
    except ValueError:
        print("Invalid Input, Please Enter Numeric Value")

print("=" * 40)
print("Thank You For Choosing M7_TROJAN Pizza! ❤️")
print(f"Please Enjoy Your Time while we get {pizzas[order-1]} pizza ready for you.")
