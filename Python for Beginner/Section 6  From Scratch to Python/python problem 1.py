name = input("Type Your Name: ")
answer = input(f"Hello, {name} What is the Weather Today?: ").lower()

if answer == "sunny":
    print("wear glasses")
elif answer == "rainy":
    print("do not forget take an umbrella")
elif answer == "cold":
    print("Do not forget to wear a jacket")
elif answer in ["good" , "great" ,"fantastic" , "pretty" , "beautiful"]:
    print("that is amazing")
elif answer in ["bad" , "worse"]:
    print("iam sorry to hear that ")
else:
    print(f"sorry {name}, i do not understand {answer}!")