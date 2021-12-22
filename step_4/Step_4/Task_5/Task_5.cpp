//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
// File: Task_5.cpp
// Summary: This program checks if a word is a palindrome
// Version: 1.1
// Owner: Jesper Malmberg
//-----------------------------------------------------------------------
// Log: 2021-12-21 Created file
//-----------------------------------------------------------------------
// Preprocessor directives
#include <iostream>


using namespace std;
// Prototypes
bool isPalindrome(char*);

const int MAXLEN = 100; // Max length of the char array

int main()
{
	char answer;

	do {
		system("CLS");			// Clear the console

		char str[MAXLEN]{'\0'};	// Empty the array
		
		cout << "Enter a word or a phrase: ";

		cin.getline(str, MAXLEN);

		// Check if palindrome and print out as apropriatey
		if (isPalindrome(str)) {
			cout << "It is a palindrome";
		} else {
			cout << "It is not a palidrome";
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
// bool isPalindrome(char *inpt)
// This function checks whether or not a word or phrase is a palindrome
// Takes a char array as input
// Returns a boolean
//-----------------------------------------------------------------------
bool isPalindrome(char *inpt) {

	// Array for backwards and copy of the input
	char backWards[MAXLEN]{'\0'};
	char copy[MAXLEN]{'\0'};
	// Indexes for copying
	int indexOriginal = 0;
	int indexCopy = 0;

	// Copy the input array backwards to backWards[]
	for (int i = strlen(inpt) - 1; i >= 0; i--) {
		if (inpt[i] != ' ') {
			backWards[indexCopy] = toupper(inpt[i]);
			indexCopy++;
		}
	}

	// Copy the input array to copy[]
	for (int i = 0; i < strlen(inpt ); i++) {
		if (inpt[i] != ' ') {
			copy[indexOriginal] = toupper(inpt[i]);
			indexOriginal++;
		}
	}

	// Compare the two arrays char by char to see if they match
	for (int i = 0; i < strlen(copy); i++) {
		if (copy[i] != backWards[i]) {
			return false;
		}
	}
	return true;
}
