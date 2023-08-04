# check if the given word starts with a vowel (I-O-U-A-E)

# define vowels 
vowels = "iouae"

# get the word from user
word = input("Enter A Word: ").strip()

# check if the given word starts with a vowel
print("=" * 30)
if word[0].lower() in vowels:
    print(f"{word} Starts With A vowel.")
else:
    print(f"{word} Doesn't Start With A Vowel.")
# .............................................................................

# another way
print("=" * 30)
for i in vowels:
    if word.lower().startswith(i):
        print(f"{word} Starts With A vowel.")
        break
else:
    print(f"{word} Doesn't Start With A Vowel.")