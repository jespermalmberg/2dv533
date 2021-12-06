//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
// File: Step_7.cpp
// Summary: This program inputst 9 doubles, removes the highest and lowest
// then returns and prints the average of the remaining 7 numbers
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
void checkInput(double);
// Global Variables
double highest = 0;		// Initialize at 0 in order to have correct reference
double lowest = 10.1;	// Initialize minimum above max theoretical score of 10.0 to have a reference value
double total = 0;		// The total score
double counter = 0;		// Counter for the inner while-loop and used for average calculation

int main() {
	char answer;		// Answer whether or not to continue
	double input;		// The input as entered by the user
	do {
		cout << "Enter 10 different integers to check which is the second highest." << endl;
		// Repeat 9 times
		while (counter < 9) {
			cout << "Enter the score and press enter: ";
			cin >> input;
			checkInput(input);
			counter++;
		}
		cout << "The average score is: " << total / (counter - 2)  << endl; // Divide total score by 7
		cout << "Do one more time (Y/N)?";
		cin >> answer;
		counter = 0;
		highest = 0;
		lowest = 0;
		total = 0;
	} while (answer == 'Y' || answer == 'y');
	return 0;
}

//-----------------------------------------------------------------
// void checkInput()
// Compares entered doubles to one another and stores highes and
// lowest. The values between gets added to total
//-----------------------------------------------------------------
void checkInput(double input) {
	// If higher than highest (starting out as 0), input becomes highest and whatever was highest gets added to the total
	if (input > highest) {
		total += highest;
		highest = input;
	}
	else if (input < lowest) {
		// If lowest has been "initialized" add the previous minimum to the total score
		if (lowest < 10.1) {
			total += lowest;
		}
		// Input becomes the lowest value
		lowest = input;
	}
	// If neither highest or lowest just add to total score.
	else {
		total += input;
	}
}
