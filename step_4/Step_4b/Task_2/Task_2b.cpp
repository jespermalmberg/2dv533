//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
// File: Task_2b.cpp
// Summary: This abbreviates name inputs
// Version: 1.1
// Owner: Jesper Malmberg
//-----------------------------------------------------------------------
// Log: 2021-12-24 Created file
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

		cout << "Enter a full name: ";

		// Get the input
		cin.getline(str, MAXLEN);

		// Length of original string
		int lenght = strlen(str);

		int index = 0;
		// Find the whitespace and copy everything including whitespace to index 1
		for (int i = 0; i < strlen(str); i++) {
			if (isspace(str[i])) {
				copy(str + i, str + lenght, str + 1);
				index = strlen(str) - i;
				// Iterate backwards and move end of string to new position
				for (int j = strlen(str); j > index; j--) {
					str[j] = '\0';
				}
			}
		}

		cout << endl;

		cout << "Treated name: ";
		for (char c : str) {
			cout << c;
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
