from faker import Faker
import csv

fake = Faker()

# Generate and print a randomly generated credit card number
print(f'Credit Card Number: {fake.credit_card_number()}')

# Generate and print full credit card details
print(f'Full Credit Card Details: {fake.credit_card_full()}')

# Get and print the credit card provider
print(f'Credit Card Provider: {fake.credit_card_provider()}')

# Get and print the randomly generated name for a credit card owner
print(f'Credit Card Owner: {fake.name()}')

# Get and print the expiration date of the credit card
print(f'Credit Card Expire: {fake.credit_card_expire()}')

# Generate and print a credit card number based on the specified card type (Visa)
print(f'Credit Card Number (Visa): {fake.credit_card_number(card_type="visa")}')

# Generate and print a credit card number based on the specified card type (Mastercard)
print(f'Credit Card Number (Mastercard): {fake.credit_card_number(card_type="mastercard")}')

# Generate and print a randomly generated credit card security code
print(f'Credit Card Security Code: {fake.credit_card_security_code()}')
