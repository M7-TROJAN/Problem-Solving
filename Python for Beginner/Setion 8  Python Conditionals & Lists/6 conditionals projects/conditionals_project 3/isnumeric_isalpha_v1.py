# check if the string contain numbers, letters, both or also other characters
# get the input
inp = input('Enter Your input: ')

# check if contains numbers only using isnumeric()
if inp.isnumeric():
    print("You Entered A Number")
# check if contains alphabets only using isalpha()
elif inp.isalpha():
    print("You Entered A String")
    # check if the letters are in upper or lower case or mix
    if inp.isupper():
        print("The Letters Is On Uppercase")
    elif inp.islower():
        print("The Letters Is On Lowercase")
    else:
        print("The letters is in both upper and lower case")
# check if contains numbers or alphabets using isalnum()
elif inp.isalnum():
    print("There Are A Mix Between Letters And Numbers.")
# otherwise there is other characters than numbers and letters
else:
    print("there is other characters than numbers and letters")


# ................................................................................
# another solution

# check if the string contain numbers, letters, both or also other characters
# get the input
inp = input('Enter Your input: ')
# check if contains numbers or alphabets using isalnum()
if inp.isalnum():
    # check if contains numbers only using isnumeric()
    if inp.isnumeric():
        print('You Entered a number')
    # check if contains alphabets only using isalpha()
    elif inp.isalpha():
        print('You Entered letters')
    # check if the letters are all lower case using islower()
        if inp.islower():
            print('All letters are lowercase')
        # check if the letters are all upper case using isupper()
        elif inp.isupper():
            print('All letters are uppercase'.upper())
        # otherwise there is letters in both upper and lower case
        else:
            print('There is a mix between uppercase and lowercase letters')
    # otherwise there is numbers and letters
    else:
        print('There is a mix between letters and numbers')
# otherwise there is other characters than numbers and letters
else:
    print('Your string did not contain alphabet and Numbers only!!')