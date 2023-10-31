from faker import Faker
import csv
import random
import datetime

# Initialize Faker and define account types
fake = Faker()
account_types = ['Group', 'People', 'Page']

def create_database(file, num_records):
    keys = ['Account ID', 'UserName', 'FirstName', 'LastName', 'Email', 'Gender', 'AccountType',
            'BirthDate', 'TotalFollowers', 'CreatedDate']

    with open(file, 'w', newline='') as f:
        w = csv.DictWriter(f, fieldnames=keys)
        w.writeheader()

        for _ in range(num_records):
            account_id = fake.uuid4()
            username = fake.user_name()
            first_name = fake.first_name()
            last_name = fake.last_name()
            email = fake.email()
            gender = fake.random_element(['Male', 'Female'])
            account_type = random.choice(account_types)
            birth_date = fake.date_of_birth(minimum_age=18, maximum_age=90)
            total_followers = fake.random_int(min=0, max=1000000)
            created_date = fake.date_time_between(start_date="-5y", end_date="now")

            w.writerow({
                'Account ID': account_id,
                'UserName': username,
                'FirstName': first_name,
                'LastName': last_name,
                'Email': email,
                'Gender': gender,
                'AccountType': account_type,
                'BirthDate': birth_date,
                'TotalFollowers': total_followers,
                'CreatedDate': created_date
            })

# File name and number of records
file_name = 'mock_database.csv'
number_of_records = 1000000

# Generate the mock database
create_database(file_name, number_of_records)
