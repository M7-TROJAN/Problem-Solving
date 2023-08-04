#include <iostream>
#include <string>
#include <fstream>
#include <limits>

using namespace std;

int main() {
    fstream file;
    file.open("D:\\myFile.txt", ios::app);

    if (file.is_open()) {
        string line;
        cout << "Enter lines of text (press Ctrl+Z followed by Enter to stop):" << endl;
        while (getline(cin, line)) {
            file << line << endl;
        }
        file.close();
        cout << "Lines written to file successfully." << endl;
    } else {
        cout << "Failed to open the file." << endl;
    }

    return 0;
}

/*

In this Example:

1- The prompt message is updated to provide instructions on how to stop entering lines of text 
by using the Ctrl+Z (Windows) or Ctrl+D (Unix/Linux) key combination.

2- The getline() function is used in the condition of the while loop. It will keep reading lines of input from cin
until it encounters the end-of-file signal (Ctrl+Z or Ctrl+D).

3- Each line of input is written to the file using file << line << endl;.

4- After the user stops entering input, the file is closed, and a success message is displayed.
*/


/*
NOte: why when the user press Ctrl+Z followed by Enter the wile loop will stop!?


In C++, when the user presses Ctrl+Z (Windows) or Ctrl+D (Unix/Linux), it generates an end-of-file (EOF)
signal on the input stream (cin). The getline() function reads input until it encounters this EOF signal,
and then it stops reading further input.

In the code provided, the condition while (getline(cin, line)) is used in the while loop.
This condition checks if the getline() function successfully reads a line from cin.
When the user presses Ctrl+Z (Windows) or Ctrl+D (Unix/Linux) to indicate the end of input,
the getline() function will fail to read another line and return false, causing the loop to terminate.

This behavior allows the user to stop entering lines of text by indicating the end of input with the Ctrl+Z or Ctrl+D key combination.
*/