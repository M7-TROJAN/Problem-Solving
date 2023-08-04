test = input("Enter A String: ").strip().lower()
if test.startswith('m'):
    print("You Won!!")
else:
    print("You Lose")

print("=" * 30)


test = input("Enter A String: ").strip().lower()
if test.endswith('m'):
    print("You Won!!")
else:
    print("You Lose")