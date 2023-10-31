from faker import Faker
import csv

fake = Faker()

# Generate and print a first name
print(f'First Name: {fake.first_name()}')

# Generate and print a first name and specify the Gender (male - female)
print(f'First Name: {fake.first_name_female()}')

# Generate and print a last name
print(f'Last Name: {fake.last_name()}')

# Generate and print a full name
print(f'Full Name: {fake.name()}')

# Generate and print a user name
print(f'Full Name: {fake.user_name()}')

# Generate and print a random email address
print(f'Email: {fake.email()}')

# Generate and print a free email address (random email address using domains from free email services such as Gmail, Yahoo, Outlook, etc.)
print(f'Free Email: {fake.free_email()}')


# Generate and print an address
print(f'Address: {fake.address()}')

# Generate and print a phone number
print(f'Phone Number: {fake.phone_number()}')

# Generate and print a credit card number
print(f'Credit Card Number: {fake.credit_card_number()}')

# Generate and print a full credit card details
print(f'Credit Card Number (Full): {fake.credit_card_full()}')

# Generate and print a job title
print(f'Job Title: {fake.job()}')

# Generate and print a company name
print(f'Company: {fake.company()}')

# Generate and print a country name
print(f'Country: {fake.country()}')

# Generate and print a date of birth between ages 18 and 70
print(f'Date of Birth: {fake.date_of_birth(minimum_age=18, maximum_age=70).isoformat()}')

# Generate and print a city name
print(f'City: {fake.city()}')

# Generate and print a state name
print(f'State: {fake.state()}')

# Generate and print a ZIP code
print(f'ZIP Code: {fake.zipcode()}')

# Generate and print random text
print(f'Text: {fake.text()}')

# Generate and print a random paragraph
print(f'Paragraph: {fake.paragraph()}')

# Generate and print a random UUID
print(f'UUID: {fake.uuid4()}')

# Generate and print a color name
print(f'Color Name: {fake.color_name()}')

# Generate and print a company email address
print(f'Company Email: {fake.company_email()}')

# Generate and print a domain name
print(f'Domain Name: {fake.domain_name()}')

# Generate and print an IPv4 address
print(f'IPv4 Address: {fake.ipv4()}')

# Generate and print a user agent string
print(f'User Agent: {fake.user_agent()}')

# Generate and print a random word
print(f'Word: {fake.word()}')

# Generate and print a random sentence
print(f'Sentence: {fake.sentence()}')

# Generate and print a URL
print(f'URL: {fake.url()}')

# Generate and print an ISBN-13 number
print(f'ISBN: {fake.isbn13()}')

# Generate and print a currency code
print(f'Currency Code: {fake.currency_code()}')

# Generate and print a barcode (EAN-13)
print(f'Barcode: {fake.ean13()}')

# Generate and print a random password
print(f'Password: {fake.password()}')

# Generate a fake job profession
print(f'Job: {fake.job()}')

# Generate a fake text with a specific number of characters
print(f'Fake Text (100 characters): {fake.text(max_nb_chars=100)}')

# Generate a fake random number
print(f'Random Number: {fake.random_number(digits=5)}')

# Generate a fake sentence with a specific number of words
print(f'Sentence (5 words): {fake.sentence(nb_words=5)}')

# Generate a fake past date within a given range
past_date = fake.date_between(start_date='-30d', end_date='-1d')
print(f'Past Date: {past_date}')

# Generate a fake future date within a given range
print(f'Future Date: {fake.future_date(end_date="+30d")}')

# Generate a fake word in a specific language
print(f'Japanese Word: {fake.word(ext_word_list="ja_JP")}')

# Generate a fake name with a prefix and/or suffix
name_with_prefix_suffix = f'{fake.prefix()} {fake.first_name()} {fake.last_name()} {fake.suffix()}'
print(f'Name with Prefix and Suffix: {name_with_prefix_suffix}')

# Generate a fake sentence with a specific pattern
print(f'Sentence with Pattern: {fake.sentence(ext_word_list=["Hello", "world"], nb_words=5)}')

# Generate a fake country code
print(f'Country Code: {fake.country_code()}')

# Generate a fake company catchphrase
print(f'Company Catchphrase: {fake.catch_phrase()}')

# Generate a fake random US Social Security Number
print(f'Social Security Number: {fake.ssn()}')

# Generate a fake job key skill
print(f'Key Skill: {fake.bs()}')

# Generate a fake street name
print(f'Street Name: {fake.street_name()}')

# Generate a fake job description
print(f'Job Description: {fake.text(max_nb_chars=200, ext_word_list=["python", "developer", "experience"])}')
