# Define a dictionary containing the languages and their scores
languages = {
    "Arabic": 0,
    "English": 0,
    "Math": 0,
    "Physics": 0,
    "Chemistry": 0,
    "Biology": 0
}

# Define the total score
TOTAL_SCORE = 600

def main():
    # Initialize a variable to store the sum of all the scores
    sum_of_scores = 0

    # Loop through each language and get the score from the user
    for language in languages:
        languages[language] = get_score(language)
        sum_of_scores += languages[language]

    # Calculate the final score
    final_score = (sum_of_scores / TOTAL_SCORE) * 100

    # Calculate the grade based on the final score
    if final_score >= 90:
        grade = 'A'
    elif final_score >= 80:
        grade = 'B'
    elif final_score >= 70:
        grade = 'C'
    elif final_score >= 60:
        grade = 'D'
    else:
        grade = 'F'

    # Print the final score and grade
    print("=" * 25)
    print(f'Your score is {final_score:.2f}%\nYour grade is {grade}')

def get_score(language):
    # Loop until a valid score is entered
    while True:
        try:
            score = float(input(f"Enter {language} score: "))
            if not (0 <= score <= 100):
                print("Error Score Should Be Between 0 and 100")
            else:
                break
        except ValueError:
            print("Invalid Input Please Enter A Numeric Value.")

    return score

main()
