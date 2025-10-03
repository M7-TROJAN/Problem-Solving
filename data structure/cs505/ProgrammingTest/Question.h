#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Question {
private:
    string text;
    vector<string> options;
    int correctOption;

public:
    Question() {}
    Question(const string& text, const vector<string>& options, int correctOption)
        : text(text), options(options), correctOption(correctOption) {}

    void setQuestionText(const string& qu)
    {
        text = qu;
    }

    void setQuestionOptions(const std::vector<std::string>& op)
    {
        options = op;
    }

    void setCorrectOption(const int& correct)
    {
        correctOption = correct;
    }

    void display() const {
        cout << "Q: " << text << "\n";
        for (int i = 0; i < options.size(); ++i) {
            cout << i + 1 << ". " << options[i] << "\n";
        }
    }

    bool isCorrect(int answer) const {
        return answer == correctOption;
    }

	int getCorrectOption() const {
		return correctOption;
	}
};