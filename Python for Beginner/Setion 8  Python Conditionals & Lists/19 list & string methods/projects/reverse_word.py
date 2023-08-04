"reverse a given string"

# get the word
word = input("Enter A word: ").strip()

# reverse the word
reversed_word = word[::-1]

# print reversing word
print("=" * 30)
print(reversed_word)

# ........................................................................................
# another solution

print("=" * 30)

# get the word
word = input("Enter A word: ").strip()

# make a list from a string
lst_word = list(word)
# reverse the list
lst_word.reverse()

# make a string from the list
reversed_word = "".join(lst_word)

# print reversing word
print("=" * 30)
print(reversed_word)
