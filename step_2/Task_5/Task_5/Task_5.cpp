//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
// File: Task_5.cpp
// Summary: This program
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
void printPattern();
int main() {

	printPattern();
	return 0;
}
//-----------------------------------------------------------------
// void printPattern()
// Prints a pattern of * symbols
//-----------------------------------------------------------------
void printPattern() {
	// Outer for-loop controls the rows of the "table"
	// Two inner for-loops prints the "columns" based on if i is even or odd
	for (int i = 0; i < 9; i++) {
		if (i % 2 == 0) {
			// Check if i is even or odd
			for (int j = 0; j < 9; j++) {
				cout << "* " << " ";
			}
			cout << endl;
		}
		else {
			for (int k = 0; k < 9; k++) {
				cout << " *" << " ";
			}
			cout << endl;
		}
	}
}
