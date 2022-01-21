//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
// File: Task_3b.cpp
// Summary: This program removes whitespaces
// Version: 1.1
// Owner: Jesper Malmberg
//-----------------------------------------------------------------------
// Log: 2021-12-24 Created file
//-----------------------------------------------------------------------
// Preprocessor directives
#include <iostream>
#include<cstring>

using namespace std;
// Prototypes
char* trimwhitespace(char* str);
const int MAXLEN = 1000; // Max length of the char array

int main()
{
	char answer;

	do {
		system("CLS");				// Clear the console

		char str[MAXLEN]{ '\0' };	// Empty the array
		
		cout << "Enter a text: ";
		// Get the input
		cin.getline(str, MAXLEN);
		// Trim input of whitespaces
		trimwhitespace(str);
			
		cout << endl;

		// Print the trimmed string
		cout << "Cleared text: ";
		for (char c : str) {
			// Print whitespace as a * for clarity
			if (isspace(c)) {
				cout << '*';
			}
			else {
				cout << c;
			}
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

//-----------------------------------------------------------------------
// trimwhitespace(*)
// This function takes a pointer to a C string and removes whitespaces
// if there are more than one. This could result in a trimmed string which
// has a whitespace in the beginning and the end. This is removed in the 
// second two steps of the function.
// 
// Returns a *char pointer to the trimmed string
//-----------------------------------------------------------------------
char* trimwhitespace(char* str) {
	
	char* strPtr = str;			// The string pointer

	// Iterate over the entire string
	for (int i = 0; i < strlen(str); i++) {
		// If the iterated index is a whitespace
		while (isspace(str[i])) {
			// Check if the index next to the iterated is a string, if not break the loop
			if (!isspace(str[i + 1])) {
				break;
			}
			// Copy substring + 1 index to the iterated index
			strcpy(str + i, strPtr + i + 1);
		}
	}

	// If first index is a whitespace shift array one to the right
	if (isspace(str[0])) {
		strcpy(str, strPtr + 1);
	}

	// If last index is a whitespace replace with null pointer
	if (isspace(str[strlen(str) - 1])) {
		str[strlen(str) - 1] = '\0';
	}
	return str;
}
