# greet the user
print("Let's see how we could deal with the weather! 😃")
print("-" * 20)

# get the temperature from the user
while True:
    try:
        weather_degree = int(input("Enter the temperature in Celsius: "))
        break
    except ValueError:
        print("Invalid input. Please enter a numeric value.")

print("-" * 20)

# define the different weather conditions
extremely_hot = f"""When the temperature is 40 or more degrees Celsius, we could say that the weather is extremely hot! 🔥🔥♨
We should avoid direct exposure to the sun. ☀☀
We should also remember to drink a lot of water! 💦"""
very_hot = f"""When the temperature is between 30 and 39 degrees Celsius, we could say that the weather is very hot! 🔥♨
We should be careful about direct exposure to the sun. ☀
We should also remember to drink a lot of water! 💦"""
moderate = f"""When the temperature is between 20 and 29 degrees Celsius, we could say that we have moderate or good weather! 🌞🌞
We should not wear clothes that are too heavy or too light. 👕"""
cold = f"""When the temperature is between 10 and 19 degrees Celsius, we could say that we have cold weather! ❄❄
We should not wear clothes that are too heavy. 👕"""
very_cold = f"""When the temperature is between 0 and 9 degrees Celsius, we could say that we have very cold weather! ❄❄❄
We should wear pretty heavy clothes. 👕"""
extremely_cold = f"""When the temperature is less than 0 degrees Celsius, we could say that we have extremely cold weather! ❄🧊🧊☃
We should avoid going outside as much as possible. 🧊🧊
We should wear really heavy clothes and never forget our heavy jacket when going outside. 🧥🧊🥶"""

# check the temperature and print the corresponding weather information
if weather_degree >= 40:
    print(extremely_hot)
elif weather_degree >= 30:
    print(very_hot)
elif 20 <= weather_degree <= 29:
    print(moderate)
elif 10 <= weather_degree <= 19:
    print(cold)
elif 0 <= weather_degree <= 9:
    print(very_cold)
else:
    print(extremely_cold)
