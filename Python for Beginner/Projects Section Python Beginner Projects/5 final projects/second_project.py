# get name, remove Extra spaces and make all lower
name = input('Enter Your Name: ').strip().lower()
# get date of birth
birth_year = input('Enter Your Birth Year: ')
birth_month = input('Enter Your Birth Month: ')
birth_day = input('Enter Your Birth Day: ')
# replace spaces with underscore
username = name.replace(' ', '_')
# username = name_day_month_(year+len(name)) @codezilla.com
username = f'{username}_{birth_day}_{birth_month}_{int(birth_year) + len(name)}'
username = f'{username}@codezilla.com'
# greet the user
print('-'*20)
print(f'Hello, {name.title()}')
# print username
print(f'Your username is ....\n{username}')