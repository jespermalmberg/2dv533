//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
// File: Task_1b.cpp
// Summary: This program takes a word and prints it backwards
// Version: 1.1
// Owner: Jesper Malmberg
//-----------------------------------------------------------------------
// Log: 2021-12-22 Created file
//-----------------------------------------------------------------------
// Preprocessor directives
#include <iostream>

using namespace std;
// Prototypes

const int MAXLEN = 100; // Max length of the char array

int main()
{
	char answer;

	do {
		system("CLS");				// Clear the console

		char str[MAXLEN]{ '\0' };	// Empty the array

		cout << "Enter a text: ";

		// Get the input
		cin.getline(str, MAXLEN);

		// The word will be stored backards in the backWards array
		char backWards[MAXLEN]{ '\0' };


		char *ptr; // The pointer
		ptr = str; // Points to the input string

		int index = 0;

		// Copy the input array backwards to backWards[]
		// Loop starts at the end of the input string and works backwards
		for (int i = strlen(str) - 1; i >= 0; i--) {

			backWards[index] = *(ptr + i);
			index++;
		}

		// Print the backwards text to the terminal
		cout << "The text backwards: "; for (int i = 0; i < strlen(backWards); i++) {
			cout << backWards[i];
		}

		cout << endl;
		cout << "Try Again (Y/N)? ";

		cin.get(answer);

		// Clear the input buffer of errors and old data
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (toupper(answer) == 'Y');

	return 0;
}
