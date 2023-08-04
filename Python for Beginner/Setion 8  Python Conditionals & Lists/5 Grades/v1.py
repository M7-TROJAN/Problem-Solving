""" Define the grade ranges and their corresponding grades"""
# Grades above 90 are excellent (A)
# Grades between 80 and 90 are very good (B)
# Grades between 70 and 80 are good (C)
# Grades between 60 and 70 are a pass (D)
# Grades between 50 and 60 are a pass with low performance (E)
# Grades below 50 are a fail (F)

# Loop until the user enters a valid score
while True:
    try:
        score = float(input("Enter Your score: "))
        # Check that the score is within the valid range of 0 to 100
        if 0 <= score <= 100:
            break
        print("please enter a score Between 0 and 100")
    except ValueError:
        print("Invalid Input You Should Enter Numeric Value")

# Check the score against the grade ranges and print the corresponding grade
if score >= 90:
    grade = "excellent (A)"
elif score >= 80:
    grade = "very good (B)"
elif score >= 70:
    grade = "good (C)"
elif score >= 60:
    grade = "pass (D)"
elif score >= 50:
    grade = 'pass "with low performance" (E)'
else:
    grade = "(F)"

print(f"Your Score is {score} And Your Grade Is {grade}.")
