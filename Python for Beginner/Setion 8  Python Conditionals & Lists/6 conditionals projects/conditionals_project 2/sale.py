# lists containing the code of items with sales
sales_70 = ['070', '170', '270', '370', '470']
sales_50 = ['050', '150', '250', '350', '450']
sales_30 = ['030', '130', '230', '330', '430']

item_code = input("Enter The Code Of The Item: ").strip()
while True:
    try:
        item_price = float(input("Enter The Price Of The Item: ").strip())
        break
    except ValueError:
        print("Invalid input. Price should be a positive numeric value.")


if item_code in sales_30:
    sale = 30
    item_price = item_price * (100 - sale)/100
elif item_code in sales_50:
    sale = 50
    item_price = item_price * (100 - sale)/100
elif item_code in sales_70:
    sale = 70
    item_price = item_price * (100 - sale)/100
else:
    sale = None

if sale is not None:
    print(f"The Final Price Of Item Code-{item_code} After {sale}% Sale Is {item_price} EGP.")
else:
    print(f"Sorry There is No Sale For This Code-{item_code} the price is {item_price} EGP.")



# ...................................................................................................................

# another solution


# Lists containing the item codes with sales
SALES = {
    '070': 70,
    '170': 70,
    '270': 70,
    '370': 70,
    '470': 70,
    '050': 50,
    '150': 50,
    '250': 50,
    '350': 50,
    '450': 50,
    '030': 30,
    '130': 30,
    '230': 30,
    '330': 30,
    '430': 30
}

# Get the item code from the user
item_code = input("Enter the code of the item: ").strip()

# Get the price of the item from the user
while True:
    try:
        item_price = float(input("Enter the price of the item: ").strip())
        if item_price <= 0:
            raise ValueError("Price should be greater than zero.")
        break
    except ValueError:
        print("Invalid input. Price should be a positive numeric value.")

# Check if a sale is applicable for the item
is_sale = False
if item_code in SALES:
    sale = SALES[item_code]
    item_price = item_price * (100 - sale)/100
    is_sale = True

# Print the final price of the item
if is_sale:
    print(f"The final price of item code {item_code} after {sale}% sale is {item_price:.2f} EGP.")
else:
    print(f"Sorry, there is no sale for item code {item_code}. The price is {item_price:.2f} EGP.")
