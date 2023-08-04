

languges = {
    "arabic": 0,
    "english": 0,
    "math": 0,
    "physics": 0,
    "chemistry": 0,
    "biology": 0}

totality = 600

def main():
    result = 0
    for languge in languges:
        languges[languge] = get_score(languge)
        result += languges[languge]

    score = (result/totality) * 100

    if score>=90:
        grade = 'A'
    elif score>=80:
        grade = 'B'
    elif score>=70:
        grade = 'C'
    elif score>=60:
        grade = 'D'
    else:
        grade = 'F'

    print("=" * 25)
    print(f'Your score is {score:.2f}%\nYour grade is {grade}')


def get_score(languge_name):
    while True:
        try:
            score = float(input(f"Enter {languge_name} score: "))
            if not (0 <= score <= 100):
                print("Error Score Should Be Between 0 and 100")
            else:
                break
        except ValueError:
            print("Invalid Input Please Enter A Numeric Value.")
    return score

main()