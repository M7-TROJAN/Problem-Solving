def validate_input(user_input):
    if user_input.isnumeric():
        return "You Entered A Number"
    elif user_input.isalpha():
        if user_input.isupper():
            return "The Letters Are In Uppercase"
        elif user_input.islower():
            return "The Letters Are In Lowercase"
        else:
            return "The Letters Are In Both Upper and Lowercase"
    elif user_input.isalnum():
        return "There Are A Mix Of Letters And Numbers"
    else:
        return "There Are Other Characters Than Numbers And Letters"

user_input = input('Enter Your input: ')
result = validate_input(user_input)
print(result)
