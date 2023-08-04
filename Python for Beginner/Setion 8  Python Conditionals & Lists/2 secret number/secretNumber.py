import random

# Start an infinite loop to keep playing until the user wants to stop
while True:
    # Generate a random number between 1 and 10
    randomNumber = random.randint(1,10)

    # Ask the user to guess the number
    while True:
        try:
            # Get input from user as integer
            number = int(input("Guess the number (between 1 and 10): "))
            # Check if the input is between 1 and 10
            if number in range(1,11):
                break
            else:
                print("Invalid input. The number should be between 1 and 10.")
        except ValueError:
            print("Invalid input. You have to type a numeric value.")

    # Check if the user guessed the correct number
    if number == randomNumber:
        print(f"Congratulations! You won! The number was {randomNumber}.")
    else:
        print(f"Sorry, it's wrong. Try again. The number was {randomNumber}.")

    # Ask the user if they want to play again
    play_again = input("Do you want to play again? (y/n): ").strip().lower()

    # If the user enters anything other than 'y' or 'yes', break out of the loop and end the program
    if play_again not in ["y","yes"]:
        print("Okay, bye!")
        break

    # If the user wants to play again, display a message indicating a new game is starting
    print("\n")
    print("Okay, here we go!")
    print("=====================")
    print("     New Game      ")
    print("=====================\n")
