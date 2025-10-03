
# Programming Test System

## Overview
This project is a "Programming Test System" designed to evaluate the user's knowledge of programming fundamentals. The system presents a series of multiple-choice questions from a predefined question bank, records the user's performance, and provides a detailed result summary. The project includes modular code organized into several files for maintainability and scalability.

---

## Project Files

### 1. `Utilities.h`
This file contains utility functions that assist the main program with common tasks. Key functionalities include:

- **`splitString`**: Splits a string into parts using a specified delimiter and returns a vector of substrings.
- **`readNumber_From_To`**: Reads and validates a number input from the user within a given range.
- **`trim`**: to trim the text from left and right and remove white spaces.

---

### 2. `StackLinkedList.h`
This file provides an implementation of the **Stack** data structure using a linked list.

- **Template**:
  - The stack is implemented generically using templates to handle any data type, including `Question`.

- **Methods**:
  - **`Push`**: Adds an element to the top of the stack.
  - **`Pop`**: Removes the top element from the stack.
  - **`Top`**: Returns the top element without removing it.
  - **`IsEmpty`**: Checks if the stack is empty.

---

### 3. `Question.h`
This file defines the **`Question`** class, which represents a single question in the test.

- **Attributes**:
  - `text`: The text of the question.
  - `options`: A vector of answer options.
  - `correctOption`: The index of the correct answer.

- **Methods**:
  - **`setQuestionText`**, **`setQuestionOptions`**, **`setCorrectOption`**: Setter methods to initialize or update question details.
  - **`display`**: Displays the question and its options.
  - **`isCorrect`**: Verifies if the user's answer matches the correct option.

---

### 4. `QuestionBank.h`
This file defines the **`QuestionBank`** class, which manages the collection of questions.

- **Attributes**:
  - `questions`: A vector of `Question` objects.

- **Methods**:
  - **`LoadQuestionsDataFromFile`**: Reads questions from a file (e.g., `Question.txt`), parses them, and populates the `questions` vector.
  - **`getRandomQuestions`**: Returns a random subset of questions for the test as a **`StackLinkedList<Question>`**.

---

### 5. `Test.h`
This file defines the **`Test`** class, which handles the core functionality of administering a test.

- **Attributes**:
  - `filePath`: Path to the questions file.
  - `playerName`: Name of the user taking the test.
  - `total_Questions`: Total number of questions in the test.
  - `number_of_Correct_Answers`: Count of correct answers.
  - `number_of_wrong_Answers`: Count of incorrect answers.
  - `questionBank`: An instance of `QuestionBank` for managing the question set.

- **Methods**:
  - **`start`**: Runs the test, displaying questions, evaluating answers, and recording results. Uses `StackLinkedList<Question>` to retrieve and manage random questions during the test.
  - **`welcome`**: Displays a welcome message and collects the user's name.
  - **`getScorePercentage`**: Calculates the user's score as a percentage.
  - **`getTestResult`**: Determines the user's grade (e.g., Pass, Fail).
  - **`addTestResultToFile`**: Saves the test results to a history file with a timestamp.
  - **`calculatingTestResult`**: Simulates the result calculation process with a loading effect.

---

### 5. `Question.txt`
This file acts as the database of questions. Each line contains:

```
QuestionText@@Option1, Option2, Option3, Option4@@CorrectOptionIndex
```

- Example:
  ```
  What is the output of: 2 + 2?@@2, 3, 4, 5@@3
  ```

---

### 6. `ProgrammingTest.cpp`
The main program file, which initializes the test system and handles user interactions.

- **Functions**:
  - **`tryAgain`**: Prompts the user to retake the test.
  - **`getTestInfo`**: Collects the desired number of questions for the test.
  - **`startTest`**: Starts a new test session.

- **`main`**:
  - Uses a loop to allow users to retake the test.
  - Seeds the random number generator for shuffling questions.

---

## Directory Structure

```
Project/
│
├── Utilities.h
├── Question.h
├── QuestionBank.h
├── StackLinkedList.h
├── Test.h
├── ProgrammingTest.cpp
├── Question.txt
└── history/
    └── (Contains daily result files)
```

---

## Execution Flow

1. The program starts with a welcome message and prompts the user to enter his/her name.
2. The user selects the number of questions they wish to answer.
3. Questions are randomly selected from the `QuestionBank` and managed using `StackLinkedList`.
4. The user answers the questions, and their performance is evaluated.
5. Results are displayed with detailed statistics (e.g., correct answers, percentage, grade).
6. Results are saved to a history file with a timestamp.
7. The user is given the option to retake the test.

---

## Sample Output

**Welcome Screen**:
```
Welcome To The Programming Fundamentals Test
Let's Test Your Knowledge!!
Please Enter Your Name to start: Mahmoud Mohammad
```

**Question**:
```
Question 1/5
Q: What is the output of: 2 + 2?
1. 2
2. 3
3. 4
4. 5
Your answer (1-4): 3
Correct!
```

**Final Results**:
```
Total Questions     : 5
Correct Answers     : 4
Wrong Answers       : 1
Score in percentage : 80%
Test Result         : Very Good
```

---

## Enhancements that we can make in the future

1. Support for adding new questions through the program.
2. Timed tests for added challenge.
3. More question categories like sports, history, etc
4. we can make it as a web application using HTML, CSS and javascript and json file holding the questions

---

## Students Name:
مسحتهم 😒

## Acknowledgments:
We want to express our gratitude to our distinguished professors for their guidance:
- Dr. Mostafa Ezzat
- Dr. Shahira Mohammad
