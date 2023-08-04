import random

random_number = random.randint(1, 10)

while True:
    try:
        guess = int(input("Guess the secret number (between 1 and 10): ").strip())
        if 0 < guess <= 10:
            break
        print("Invalid input! Please enter a number between 1 and 10.")
    except ValueError:
        print("Invalid input! Please enter a numeric value between 1 and 10.")

print("=" * 30)
if guess == random_number:
    print(f"Congratulations! You guessed the secret number ({guess}).")
else:
    print(f"Sorry, you lost. The secret number was {random_number}.")
