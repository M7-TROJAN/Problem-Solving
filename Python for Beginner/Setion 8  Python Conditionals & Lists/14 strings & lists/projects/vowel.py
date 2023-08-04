
# Define vowels 
vowels = "iouae"

# Prompt the user to enter a word
while True:
    word = input("Enter a word: ").strip().lower()
    if word:
        break
    print("Please enter a non-empty word.")

# Prompt the user to guess whether the word starts with a vowel
valid_responses = {"y", "yes", "n", "no"}
while True:
    guess = input("Does the word start with a vowel? (y/n): ").strip().lower()
    if guess in valid_responses:
        break
    print(f"Invalid response. Please enter one of {valid_responses}.")

# Check if the guess is correct
if (word[0] in vowels and guess in {"y", "yes"}) or (word[0] not in vowels and guess in {"n", "no"}):
    print("Congratulations, you're correct!")
    if word[0] in vowels:
        print(f"{word} starts with a vowel.")
    else:
        print(f"{word} doesn't start with a vowel.")
else:
    print("Sorry, that's incorrect. Please try again.") 
