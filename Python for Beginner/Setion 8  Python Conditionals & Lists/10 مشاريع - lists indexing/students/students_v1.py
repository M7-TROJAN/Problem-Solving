
# a list of students’ ids
students = [
    # Codezilla school
    ['1100', '1101', '1102', '1103', '1104', '1105', '1106', '1107', '1108', '1109'],
    # Al Dorra school
    ['2100', '2101', '2102', '2103', '2104', '2105', '2106', '2107', '2108', '2109'],
    # Mostafa Kamel school
    ['3100', '3101', '3102', '3103', '3104', '3105', '3106', '3107', '3108', '3109']
]

while True:
    student_id = input("Please enter the student ID (4 digits): ")
    if student_id.isdigit() and len(student_id) == 4:
        break
    else:
        print("Invalid input. Please enter a 4-digit student ID.")

print("=" * 50)

for school in students:
    if student_id in school:
        print(f"Student {student_id} is enrolled in {students.index(school) + 1}.")
        break
else:
    print(f"Sorry, student {student_id} is not in our records.")
