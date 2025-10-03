#pragma once
#include "Question.h"
#include "Utilities.h"
#include "StackLinkedList.h"
#include <fstream> // For file I/O
#include <cstdlib> // For srand() and rand()
#include <ctime>   // For time()

class QuestionBank {
private:
    vector<Question> questions;
    bool ConvertLineToRecord(const string& line, Question& question, const string& separator = "@@")
    {
        vector<string> record = splitString(line, separator);
        if (record.size() != 3)
        {
            return false; // Error: Incorrect number of data elements
        }
        string QuText = record[0];
        vector<string> options = splitString(record[1], ", ");
        int correctOption = std::stoi(record[2]);
        question.setQuestionText(QuText);
        question.setQuestionOptions(options);
        question.setCorrectOption(correctOption);
        return true;
    }

public:
    void LoadQuestionsDataFromFile(const string& filePath)
    {
        std::ifstream file(filePath);
        if (file.is_open())
        {
            int lineNumber = 0; // just for debugging
            std::string line;
            Question question;
            while (std::getline(file, line))
            {
                lineNumber++;
                line = trim(line);
                if (ConvertLineToRecord(line, question, "@@"))
                {
                    questions.push_back(question);
                }
                else
                {
                    std::cerr << "Unexpected Error While Reading Question Line number: " << lineNumber << std::endl;
                    break;
                }
            }
            file.close();
        }
        else
        {
            std::cerr << "Error opening file: " << filePath << std::endl;
        }
    }

    StackLinkedList<Question> getRandomQuestions(int count) const {
        vector<Question> shuffled = questions;

        // shuffle the vector
        for (int i = 0; i < shuffled.size(); i++) {
            int randomIndex = rand() % shuffled.size(); // Generate random index
            swap(shuffled[i], shuffled[randomIndex]); // Swap elements
        }

        // Ensure that 'count' is not greater than the number of questions
        if (count > shuffled.size()) {
            count = shuffled.size();
        }

        // create a stack of questions and push the random questions into the stack
        StackLinkedList<Question> stack;
        for (int i = 0; i < count; i++) {
            stack.Push(shuffled[i]);
        }

		return stack;
    }

  

	// the below is return type of getRandomQuestions is vector<Question> instead of StackLinkedList<Question>

    /* vector<Question> getRandomQuestions(int count) const {
        vector<Question> shuffled = questions;

        // shuffle the vector
        for (int i = 0; i < shuffled.size(); i++) {
            int randomIndex = rand() % shuffled.size(); // Generate random index
            swap(shuffled[i], shuffled[randomIndex]); // Swap elements
        }

        // Ensure that 'count' is not greater than the number of questions
        if (count > shuffled.size()) {
            count = shuffled.size();
        }

        // Create a new vector with the first 'count' elements
        vector<Question> result;
        for (int i = 0; i < count; i++) {
            result.push_back(shuffled[i]);
        }

        return result;
    }*/


	// the below is advanced version of getRandomQuestions using shuffle algorithm and mt19937 random number generator instead of rand()

    /*vector<Question> getRandomQuestions(int count) const {
        vector<Question> shuffled = questions;
        shuffle(shuffled.begin(), shuffled.end(), std::mt19937{ std::random_device{}() });
        if (count > shuffled.size()) count = shuffled.size();
        return vector<Question>(shuffled.begin(), shuffled.begin() + count);

        // do not forget to include <algorithm> and <random> headers for shuffle and mt19937
        // #include <algorithm> // For shuffle
        // #include <random> // For random_device
    }*/
};