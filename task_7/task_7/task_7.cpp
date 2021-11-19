//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
// File: Source.cpp
// Summary: This program adds the individual digits of a 3 digit number
// Version: 1.1
// Owner: Jesper Malmberg
//-----------------------------------------------------------------------
// Log: 2021-11-19 Created file
//-----------------------------------------------------------------------
// Preprocessor directives
#include <iostream>
#include <iomanip>
#include <typeinfo>

using namespace std;
// Prototypes
void numberAddition();
int numberLength(int);

int main() {
	char answer;
	do {
		numberAddition();
		cout << "One more time? (Y/N): ";
		cin >> answer;
	} while (answer == 'Y' || answer == 'y');
	return 0;
}
//-----------------------------------------------------------------
// void numberAddition()
//-----------------------------------------------------------------
void numberAddition() {
	int number;
	int first, second, third;
	cout << "Enter a three-digit number: ";
	cin >> number;
	// Check that the entered data-type is integer.
	/*while (!(cin >> number)) {
		cout << "Make sure you enter an integer...\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> number;
	}*/

	// Check that number entered is exactly 3 digits.
	if (numberLength(number) != 3) {
		cout << "Make sure the number entered is exactly 3 digits...";
		cout << endl;
		numberAddition(); // Run again if incorrect number entered.
	}
	else {
		// Split three digit number into individual digits
		first = number / 100;
		second = (number % 100) / 10;
		third = number % 10;

		cout << "The sum of the three digits is: " << first + second + third;
		cout << endl;
	}
}

//-----------------------------------------------------------------
// int numberLenght()
// Checks the length of an entered int
// Returns an int
//-----------------------------------------------------------------
int numberLength(int number) {
	int counter = 0;
	while (number) {
		number = number / 10;
		counter++;
	}
	return counter;
}
