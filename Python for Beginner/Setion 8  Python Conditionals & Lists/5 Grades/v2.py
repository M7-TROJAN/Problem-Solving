# Define the grade ranges and their corresponding grades
grade_ranges = [
#   (min,max, grade letter)
    (90, 100, "Excellent (A)"),
    (80, 90, "Very Good (B)"),
    (70, 80, "Good (C)"),
    (60, 70, "Pass (D)"),
    (50, 60, "Pass (E)"),
    (0, 50, "Fail (F)")
]

# Loop until the user enters a valid grade
while True:
    try:
        grade = float(input("Enter Your Grade: "))
        break
    except ValueError:
        print("Invalid Input You Should Enter Numeric Value")

# Find the grade range that the grade belongs to and print the corresponding grade
for range_min, range_max, grade_letter in grade_ranges:
    if range_min <= grade <= range_max:
        print(grade_letter)
        break