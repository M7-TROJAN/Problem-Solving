from random import randint

# random coin flip
coin_flip = randint(1,2)

# opening message
print("""Guess The Coin Flip!
Enter
1 For Heads
2 For Tails""")

# get the guess from the user
while True:
    try:
        guess = int(input("Enter Your Choice: "))
        if guess not in [1,2]:
            raise ValueError
        break
    except ValueError:
        print("Invalid input! Please enter a numeric value 1 OR 2.")

print('-'*20)
# print the coin flip
if coin_flip == 1:
    print("The Coin is Heads")
else:
    print("The Coin is Tails")

# check if the user guessed correctly
if guess == coin_flip:
    print("You Won!")
else:
    print("You Lost!")
