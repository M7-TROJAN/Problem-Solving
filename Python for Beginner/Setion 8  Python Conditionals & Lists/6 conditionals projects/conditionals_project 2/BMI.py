# bad solution

# """ BMI CALCULATOR """
# """
# BMI	               Weight Status
# Below 18.5	        Underweight
# 18.5 - 24.9	        Healthy Weight
# 25.0 - 29.9	        Overweight
# 30.0 and Above	    Obesity
# """

# # get height
# while True:
#     try:
#         height = float(input("Enter Height In Cm: "))
#         break
#     except ValueError:
#         print("Invalid Input height should ba a numeric value.")

# #  get weight
# while True:
#     try:
#         weight = float(input("Enter weight In kg: "))
#         break
#     except ValueError:
#         print("Invalid Input weight should ba a numeric value.")

# # calculate BMI
# bmi = weight / ((height/100) * (height/100))


# # check Weight Status
# if bmi <= 18.5:
#     WeightStatus = 'Underweight'
# elif 18.5 < bmi <= 24.9:
#     WeightStatus = 'Healthy Weight'
# elif 25 <= bmi <= 29.9:
#     WeightStatus = 'Overweight'
# else:
#     WeightStatus = 'Obesity'

# # print 
# print(f"Your BMI Is {bmi:.1f} which Is considered as {WeightStatus}")

#......................................................................................................


# best solution

# Define the weight status categories
WEIGHT_STATUS = {
    (0, 18.5): 'Underweight',
    (18.5, 25): 'Healthy Weight',
    (25, 30): 'Overweight',
    (30, float('inf')): 'Obesity'
}

# Get the user's height in cm
while True:
    try:
        height = float(input("Enter Height In Cm: "))
        if height <= 0:
            raise ValueError("Height should be greater than zero.")
        break
    except ValueError:
        print("Invalid input. Height should be a positive numeric value.")

# Get the user's weight in kg
while True:
    try:
        weight = float(input("Enter Weight In kg: "))
        if weight <= 0:
            raise ValueError("Weight should be greater than zero.")
        break
    except ValueError:
        print("Invalid input. Weight should be a positive numeric value.")

# Calculate the user's BMI
bmi = weight / ((height/100) ** 2)

# Determine the user's weight status based on their BMI
for range_, status in WEIGHT_STATUS.items():
    if range_[0] < bmi <= range_[1]:
        weight_status = status
        break

# Print the user's BMI and weight status
print(f"Your BMI is {bmi:.1f}, which is considered {weight_status}.")