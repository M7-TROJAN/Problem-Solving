
# greeting
print('let\'s see how we could deal with the weather 😃')
print('-'*20)


while True:
    try:
        # get the temperature
        weatherdegree = int(input("Enter The Degree In Celsius: "))
        break
    except ValueError:
        print("invalid Input Type A nUmeric Value Please")

print('-'*20)

# weather info
extremely_hot = """When the degree is 40 or more
We could say that the weather is extremely hot 🔥🔥♨
we should avoid direct exposure to The Sun ☀☀
We should also remember to drink a lot of water 💦
"""
very_hot = """When the degree is 30 or more
We could say that the weather is very hot 🔥♨
we should be careful about direct exposure to The Sun ☀
We should also remember to drink a lot of water 💦
"""
moderate = """When the degree is between 20 and 30
We could say that we have moderate or good weather 🌞🌞
We should not go with too heavy nor too light clothes 👕
"""
cold = """When the degree is between 10 and 20
We could say that we have cold weather ❄❄
We should not go with pretty heavy clothes 👕
"""
very_cold = """When the degree is between 0 and 10
We could say that we have very cold weather ❄❄❄
We should go with pretty heavy clothes 👕
"""
extremely_cold = """When the degree is less than 0
We could say that we have extremely cold weather ❄🧊🧊☃
We should avoid getting out as possible 🧊🧊
We should go with really heavy clothes 👕
Never forget your Heavy Jacket 🧥 when you are going out 🧊🥶
"""


# check the degree and print the result
if weatherdegree >= 40:
    print(extremely_hot)
elif weatherdegree >= 30:
    print(very_hot)
elif  20 <= weatherdegree <= 30:
    print(moderate)
elif 10 <= weatherdegree <= 20:
    print(cold)
elif 0 <= weatherdegree <= 10:
    print(very_cold)
else:
    print(extremely_cold)

# greeting
print('let\'s see how we could deal with the weather 😃')
print('-'*20)


while True:
    try:
        # get the temperature
        weatherdegree = int(input("Enter The Degree In Celsius: "))
        break
    except ValueError:
        print("invalid Input Type A nUmeric Value Please")

print('-'*20)

# weather info
extremely_hot = """When the degree is 40 or more
We could say that the weather is extremely hot 🔥🔥♨
we should avoid direct exposure to The Sun ☀☀
We should also remember to drink a lot of water 💦
"""
very_hot = """When the degree is 30 or more
We could say that the weather is very hot 🔥♨
we should be careful about direct exposure to The Sun ☀
We should also remember to drink a lot of water 💦
"""
moderate = """When the degree is between 20 and 30
We could say that we have moderate or good weather 🌞🌞
We should not go with too heavy nor too light clothes 👕
"""
cold = """When the degree is between 10 and 20
We could say that we have cold weather ❄❄
We should not go with pretty heavy clothes 👕
"""
very_cold = """When the degree is between 0 and 10
We could say that we have very cold weather ❄❄❄
We should go with pretty heavy clothes 👕
"""
extremely_cold = """When the degree is less than 0
We could say that we have extremely cold weather ❄🧊🧊☃
We should avoid getting out as possible 🧊🧊
We should go with really heavy clothes 👕
Never forget your Heavy Jacket 🧥 when you are going out 🧊🥶
"""


# check the degree and print the result
if weatherdegree >= 40:
    print(extremely_hot)
elif weatherdegree >= 30:
    print(very_hot)
elif  20 <= weatherdegree <= 30:
    print(moderate)
elif 10 <= weatherdegree <= 20:
    print(cold)
elif 0 <= weatherdegree <= 10:
    print(very_cold)
else:
    print(extremely_cold)
