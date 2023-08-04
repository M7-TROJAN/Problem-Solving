# Define lists of countries and their weekends
# Note: Use uppercase for constants
COUNTRIES_FRI_SAT = ['egypt', 'saudi arabia', 'ksa', 'kuwait'] 
COUNTRIES_SAT_SUN = ['australia', 'usa', 'united']

# Prompt the user for a country name and convert it to lowercase
country = input("Enter Country Name: ").strip().lower()

# Check if the country is in the list of countries with Friday and Saturday weekends
if country in COUNTRIES_FRI_SAT:
    print(f"Friday and Saturday Are The Weekends In {country.capitalize()}") # Capitalize the first letter of the country name in the output
# Check if the country is in the list of countries with Saturday and Sunday weekends
elif country in COUNTRIES_SAT_SUN:
    print(f"Saturday and Sunday Are The Weekends In {country.capitalize()}")
else:
    print("Sorry, I don't know which days are the weekends in that country.") # Provide a more user-friendly error message
