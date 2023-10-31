from faker import Faker
import csv

def create_fake_data(file_name, num_rows):
    # Define the fields to be generated
    keys = ['name', 'job', 'phone', 'email', 'country', 'salary']
    
    fake = Faker()
    
    with open(file_name, 'w', newline='') as file:
        writer = csv.DictWriter(file, fieldnames=keys)
        writer.writeheader()

        for _ in range(num_rows):
            writer.writerow({
                'name': fake.name(),
                'job': fake.job(),
                'phone': fake.phone_number(),
                'email': fake.free_email(),
                'country': fake.country(),
                'salary': fake.random_int(min=3500, max=25000)
            })

def main():
    file_name = input('Enter File Name (without extension): ') + '.csv'
    num_rows = int(input('Enter Number of Rows: '))

    create_fake_data(file_name, num_rows)
    print(f'Generated {num_rows} rows of fake data in "{file_name}".')

if __name__ == "__main__":
    main()