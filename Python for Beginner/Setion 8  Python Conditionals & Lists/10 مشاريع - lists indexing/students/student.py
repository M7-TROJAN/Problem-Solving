# a list of students' ids
students = [
# Codezilla school
['1100', '1101', '1102', '1103', '1104',
'1105', '1106', '1107', '1108', '1109'],
# Al Dorra school
['2100', '2101', '2102', '2103', '2104',
'2105', '2106', '2107', '2108', '2109'],
# Mostafa Kamel school
['3100', '3101', '3102', '3103', '3104',
'3105', '3106', '3107', '3108', '3109']
]
# available schools, and students in each school
codezilla_school = students[0]
al_dorra_school = students[1]
mostafa_kamel_school = students[2]
# a message to ask for student id
student_id = input("Enter student id: ")
print('-' * 50)
# check the school of the student
if student_id in codezilla_school:
    print("Student is in Codezilla School")
elif student_id in al_dorra_school:
    print("Student is in Al Dorra School")
elif student_id in mostafa_kamel_school:
    print("Student is in Mostafa Kamel School")
else:
    print("Sorry, Student is not in our records")