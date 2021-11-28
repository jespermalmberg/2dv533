//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
// File: Step_6.cpp
// Summary: This program compares 10 integers and prints the second highest
// Version: 1.1
// Owner: Jesper Malmberg
//-----------------------------------------------------------------------
// Log: 2021-11-27 Created file
//-----------------------------------------------------------------------
// Preprocessor directives
#include <iostream>
#include <iomanip>
using namespace std;
// Prototypes
void compareIntegers(int);
// Global Variables
int highest = 0;
int secondHighest = 0;

int main() {

	int counter = 0;	// Counter for the inner while-loop
	char answer;		// Answer whether or not to continue
	int input;			// The input as entered by the user
	do {
		cout << "Enter 10 different integers to check which is the second highest." << endl;
		// Repeat 10 times
		while (counter < 10) {
			cout << "Enter an integer and press enter: ";
			cin >> input;
			compareIntegers(input);
			counter++;
		}
		cout << "The second highest entered integer is: " << secondHighest<< endl;
		cout << "Do one more time (Y/N)?" ;
		cin >> answer;
		counter = 0;
		highest = 0;
		secondHighest = 0;
	} while (answer == 'Y' || answer == 'y');
	return 0;
}
//-----------------------------------------------------------------
// void compareIntegers()
// Compares entered integers to one another and stores highes and
// second highest
//-----------------------------------------------------------------
void compareIntegers(int input) {
	// If input is higher than stored highest integer the input becomes
	// the highest and the old highest becomes second highest
	if (input >= highest) {
		secondHighest = highest;
		highest = input;
	// If the input is between secondHighest and highest the input becomes
	// the second highest
	} else if (input > secondHighest) {
		secondHighest = input;
	}
}
