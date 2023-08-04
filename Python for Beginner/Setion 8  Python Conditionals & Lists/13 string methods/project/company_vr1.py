import random
name = input("Enter Your Name: ").strip().title()
company_name = input("Enter Your Company Name: ").strip().title()
birth_year = int(input("Enter Your Birth Year: "))

# id = first 3 characters of company name + - + last 2 characters of name + birth year + random number
id = company_name[:4] + "-" + name[-2:] + str(birth_year) + str(random.randint(1,9))
while True:
    try:
        email = input("Enter Your Email: ").strip().lower()
        index_of_at = email.index("@")
        company_email = email[:index_of_at+1] + company_name + ".com"
        break
    except ValueError:
        print("Invalid email address. Please try again.")


print("=" * 30)
print(f"Hello, {name} ! \nWelcome To {company_name}!!")
print("=" * 30)
print(f"Your Id Is {id}")
print(f"Your Email Is {company_email}")
