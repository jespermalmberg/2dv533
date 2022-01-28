//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
// File: Task_4b.cpp
// Summary: This program reduces words to acronyms.
// Version: 1.1
// Owner: Jesper Malmberg
//-----------------------------------------------------------------------
// Log: 2022-01-02 Created file
//-----------------------------------------------------------------------
// Preprocessor directives
#include <iostream>
#include<cstring>

using namespace std;
// Prototypes
bool isConsonant(char c);
char* abbreviate(char* str);
char* rmDoubleConsonant(char* str);

const int MAXLEN = 1000; // Max length of the char array
int main()
{
	char answer;

	do {
		system("CLS");					// Clear the console

		char str[MAXLEN]{ '\0' };		// Empty the array
		char conString[MAXLEN]{ '\0' };	// Empty the array

		cout << "Enter a text: ";
		// Get the input
		cin.getline(str, MAXLEN);

		// Remove all the vowels in the word
		int index = 0;
		for (char c : str) {
			if (isConsonant(c)) {
				conString[index] = c;
				index++;
			}
		}
		
		// Abbreviate to military style
		abbreviate(conString);

		// Print the result
		cout << conString;
		cout << endl;

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
// isConsonant(char)
// Checks if a single character is a consonant and returns true if true
// Returns: Boolean
//-----------------------------------------------------------------------
bool isConsonant(char c) {
	char c1 = toupper(c);
	if (c1 == 'A' || c1 == 'O' || c1 == 'U' || c1 == 'E' || c1 == 'I' || c1 == 'Y') {
		return false;
	}
	return true;
}

//-----------------------------------------------------------------------
// abbreviate(char*)
// Abbreviates a consonant string according to the following rules:
// 1. Doubble consonants are treated as 1
// 2. Words with more than 5 consonants are abbreviated keeping the first
// three and last two letters
// 3. Words with 5 or less consonants keep them all unless there are double
// 
// Returns: char*
//-----------------------------------------------------------------------
char* abbreviate(char* str) {

	// 5 or less letter words
	if (strlen(str) <=5) {
		rmDoubleConsonant(str);
		return str;
	}
	// More than 5 letters
	else {
		strcpy(str + 3, str + strlen(str) - 2);
		rmDoubleConsonant(str);
		return str;
	}
}

//-----------------------------------------------------------------------
// rmDoubleConsonant(char*)
// Checks for more than 1 consonant together and reduces so that there is 
// only one. I.e no double consonants.
// 
// Returns: char*
//-----------------------------------------------------------------------
char* rmDoubleConsonant(char* str) {
	
	for (int i = 0; i < strlen(str) - 1; i++) {
		while (str[i] == str[i + 1]) {
			strcpy(str + i, str + i + 1);
		}
	}
	return str;
}
