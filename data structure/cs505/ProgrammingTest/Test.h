#pragma once
#include "QuestionBank.h"
#include <Windows.h> // For Sleep

class Test {
private:
    const string filePath = "Question.txt";
    string playerName;
    int total_Questions;
    int number_of_Correct_Answers;
    int number_of_wrong_Answers;
    QuestionBank questionBank;

    short getScorePercentage()
    {
        short percentage = (number_of_Correct_Answers / total_Questions) * 100;
        return percentage;
    }

    string getTestResult()
    {
        int perc = getScorePercentage();
        if (perc < 60)
            return "Fail";
        else if (perc >= 60)
            return "pass";
        else if (perc >= 70)
            return "Good";
        else if (perc >= 80)
            return "Very Good";
        else if (perc >= 90 && perc <= 100)
            return "Excellent";

        return "Unknown";
    }

    void calculatingTestResult()
    {
        cout << "\n\nCalculating the test result ";
        for (int i = 0; i < 6; i++)
        {
            cout << ".";
            Sleep(1000);
        }
        cout << endl;

        theEnd();
    }

    void theEnd()
    {
        system("cls");
        cout << "\n\n";
        cout << "                       ----------------------------------------------------------------------\n";
        cout << "                       |                       +++ T H E  E N D +++                         |\n";
        cout << "                       ----------------------------------------------------------------------\n";
        cout << "\n";
        cout << "                       -------------------------- [Final Results] ---------------------------\n";
        cout << "                       Total Questions     : " << total_Questions << "\n";
        cout << "                       Correct Answers     : " << number_of_Correct_Answers << "\n";
        cout << "                       Wrong Answers       : " << number_of_wrong_Answers << "\n";
        cout << "                       Score in percentage : " << getScorePercentage() << "%\n";
        cout << "                       Test Result         : " << getTestResult() << "\n";
        cout << "                       ----------------------------------------------------------------------" << std::endl;

        if (getScorePercentage() > 60)
        {
			cout << "\n\n";
			cout << "                       -------------------------- [Congratulations] --------------------------\n";
			cout << "                       |                     You have passed the test!                       |\n";
			cout << "                       -----------------------------------------------------------------------\n";
			system("color 2f");
		}
		else
		{
			cout << "\n\n";
			cout << "                       ------------------------------ [Sorry] ------------------------------\n";
			cout << "                       |                     You have failed the test!                     |\n";
			cout << "                       ---------------------------------------------------------------------\n";
			system("color 4f");
        }
    }

    void addTestResultToFile()
    {
        time_t currentTime = time(nullptr);
        tm localTime;
        localtime_s(&localTime, &currentTime);

        // get date
        short day = localTime.tm_mday;
        short month = localTime.tm_mon + 1;
        short year = localTime.tm_year + 1900;
        string date = to_string(day) + "-" + to_string(month) + "-" + to_string(year);

        // get hour
        short hour24 = localTime.tm_hour;
        short hour12 = hour24 % 12;
        short minute = localTime.tm_min;
        short second = localTime.tm_sec;
        const char* amPmIndicator = (hour24 < 12) ? "AM" : "PM";
        // check if hour12 is equal  0
        if (hour12 == 0)
            hour12 = 12; // Convert 0 to 12 in the 12-hour time format

        string time = to_string(hour12) + ":" + to_string(minute) + ":" + to_string(second) + amPmIndicator;

        std::fstream MyFile;
        std::string filePath = "history\\" + date + ".txt";
        MyFile.open(filePath, std::ios::app);
        if (MyFile.is_open())
        {
            MyFile << "\n\n";
            MyFile << "                           " << date << " | " << time << "\n";
            MyFile << "----------------------------- [Test Results] -------------------------\n";
            MyFile << "Player Name: " << playerName << "\n";
            MyFile << "total Questions: " << total_Questions << "\n";
            MyFile << "correct answers: " << number_of_Correct_Answers << "\n";
            MyFile << "wrong answers: " << number_of_wrong_Answers << "\n";
            MyFile << "Grade: " << getTestResult() << "\n";
            MyFile << "----------------------------------------------------------------------\n";
            MyFile.close();
        }
    }

    void welcome()
    {
        cout << "\n";
        cout << "                ---------------------------------------------------------------------------------------------\n";
        cout << "                |*********************** Welcome To The Programming Fundamentals Test **********************|\n";
        cout << "                ---------------------------------------------------------------------------------------------\n";
        cout << "                                                  Let's Test Your Knowledge!!\n";
        cout << "                ---------------------------------------------------------------------------------------------\n\n";
        cout << "                                                  Please Enter Your Name to start: ";
        cin >> playerName;
        playerName = trim(playerName);
        cin.clear();
        cin.ignore(10000, '\n');
        system("cls");
    }

public:
    Test(const int& numberOfQuestions) {
        total_Questions = numberOfQuestions;
        number_of_Correct_Answers = 0;
        number_of_wrong_Answers = 0;
        questionBank.LoadQuestionsDataFromFile(filePath);
    }


	// Function to start the test using the questionBank.getRandomQuestions function that returns a StackLinkedList<Question>
	void start()
	{
		system("cls");
		system("color 0f");
		welcome();
		StackLinkedList<Question> selectedQuestions = questionBank.getRandomQuestions(total_Questions);
		int questionNumber = 1;
		while (!selectedQuestions.IsEmpty())
		{
			Question q = selectedQuestions.Top();
			std::cout << "\nQuestion " << questionNumber++ << "/" << total_Questions << "\n";
			q.display();
			selectedQuestions.Pop();

			int answer;
			answer = readNumber_From_To(1, 4, "Your answer (1-4): ");

			if (q.isCorrect(answer)) {
				system("color 2f");
				std::cout << "Correct!\n";
				number_of_Correct_Answers++;
				Sleep(1000);
				system("color 0f");
			}
			else {
				system("color 4f");
				std::cout << "Wrong! The correct answer was: " << q.getCorrectOption() << "\n";
				number_of_wrong_Answers++;
				Sleep(1000);
				system("color 0f");
			}
		}

		addTestResultToFile();
		calculatingTestResult();
	}


	// Function to start the test using the questionBank.getRandomQuestions function that returns a vector<Question>
    /*void start()
    {
        system("cls");
        system("color 0f");
        welcome();
        vector<Question> selectedQuestions = questionBank.getRandomQuestions(total_Questions);
        for (int i = 0; i < selectedQuestions.size(); ++i) {
            std::cout << "\nQuestion " << i + 1 << "/" << selectedQuestions.size() << "\n";
            selectedQuestions[i].display();

            int answer;
            answer = readNumber_From_To(1, 4, "Your answer (1-4): ");

            if (selectedQuestions[i].isCorrect(answer)) {
                system("color 2f");
                std::cout << "Correct!\n";
                number_of_Correct_Answers++;
				Sleep(1000);
				system("color 0f");
            }
            else {
                system("color 4f");
                std::cout << "Wrong! The correct answer was: " << selectedQuestions[i].getCorrectOption() << "\n";
				number_of_wrong_Answers++;
				Sleep(1000);
				system("color 0f");
            }
        }

        addTestResultToFile();
        calculatingTestResult();
    }*/
};