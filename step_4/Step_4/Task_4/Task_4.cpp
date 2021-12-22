//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
// File: Task_4.cpp
// Summary: This program checks if a social security number belongs to a
//			man or a woman
// Version: 1.1
// Owner: Jesper Malmberg
//-----------------------------------------------------------------------
// Log: 2021-12-20 Created file
//-----------------------------------------------------------------------
// Preprocessor directives
#include <iostream>
#include <cstdlib> // atoi()
#include <cctype> // isdigit()

using namespace std;
// Prototypes
bool checkSsn(char*);
void ssnManOrWoman(char*);

// Constants
const int MAXLEN = 99; // Length of array

int main()
{


	char str[MAXLEN]{ '\0' };
	char answer;			// Continue or stop program variable
	bool ssnOk;

		do {
			system("CLS");
			cout << "Please enter a social security number: ";

			do {
				// Char array for input
				char ssn[MAXLEN] = { '\0' };
				
				// Read input
				cin.getline(ssn, MAXLEN);

				ssnOk = checkSsn(ssn);

				if (!ssnOk) {
					cout << "Invalid number, please enter the number in format: YYMMDD-XXXX:";
				}

				if (ssnOk) {
					ssnManOrWoman(ssn);
				}

			} while (!ssnOk);
			
			cout << endl;
			cout << "Want to check another Social Security Number (Y/N)? ";
			cin.get(answer);

			// Clear the input buffer of errors and old data
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		} while(toupper(answer) == 'Y');

	return 0;
}

//-----------------------------------------------------------------------
// bool checkSsn(char *ssn)
// Checks that an entered ssn number is ok
// Takes an array pointer
// Returns a boolean
//-----------------------------------------------------------------------
bool checkSsn(char *ssn) {
	// Check if entered number is too long
	if (ssn[11]) {
		return false;
	}

	// Check if a hyphen is present and remove it if so
	if (ssn[6] == '-') {
		for (int i = 7; i < 10; i++) {
			ssn[i - 1] = ssn[i];
		}
	}
	// Check that all char are digits
	for (int i = 0; i < 10; i++) {
		if (!isdigit(ssn[i])) {
			return false;
		}
	}
	return true;
}

//-----------------------------------------------------------------------
// void ssnManOrWoman(char* ssn)
// Checks if a SSN belongs to a man or woman
// Takes an array pointer
//-----------------------------------------------------------------------
void ssnManOrWoman(char* ssn) {
	// If even it belongs to a woman
	if (ssn[8] % 2 == 0) {
		cout << "The SSN ";
		for (int i = 0; i < 10; i++) {
			cout << ssn[i];
		}
		cout << " belongs to a woman";
	}
	else {
		// Else it belongs to a man
		cout << "The SSN ";
		for (int i = 0; i < 10; i++) {
			cout << ssn[i];
		}
		cout << " belongs to a man";
	}
}
