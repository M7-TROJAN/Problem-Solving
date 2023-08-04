# a dictionary of schools and their students' IDs
students = {
    "Codezilla school"     : ['1100', '1101', '1102', '1103', '1104', '1105', '1106', '1107', '1108', '1109'],
    "Al Dorra school"      : ['2100', '2101', '2102', '2103', '2104', '2105', '2106', '2107', '2108', '2109'],
    "Mostafa Kamel school" : ['3100', '3101', '3102', '3103', '3104', '3105', '3106', '3107', '3108', '3109']
}

# ask for a student ID
student_id = input("Enter the student ID: ")
print("=" * 50)

# loop through the schools and their students' IDs to check if the input ID exists
for school, ids in students.items():
    if student_id in ids:
        # if the input ID exists, print the school name and break the loop
        print(f"Student is in {school}.")
        break
else:
    # if the input ID doesn't exist, print a message
    print("Sorry, the student is not in our records.")
