//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
// File: Task_1.cpp
// Summary: This program takes a random number of integers to a dynamic
//			array.
// Version: 1.1
// Owner: Jesper Malmberg
//-----------------------------------------------------------------------
// Log: 2022-01-01 Created file
//-----------------------------------------------------------------------
// Preprocessor directives
#include <iostream>
#include<cstring>
#include <algorithm>
#include <iterator>

using namespace std;
// Prototypes

int main()
{
	char answer;

	do {
		system("CLS");				// Clear the console

		int counter = 0;
		int* arr = new int[0];		// The initial array
		int i;						// Stores the input
		cout << "Enter integer numbers to store (Stop by entering any non-numeric value):";
		while(cin >> i) {

			counter++;
			int *tempo = new int[counter];	// Temporary array = arr + 1 in lenght

			copy(arr, arr + counter, tempo); // Copy the contents of arr to tempo

			tempo[counter - 1] = i;	// Insert the input at last index of tempo

			delete []arr;	// Delete the first array

			arr = tempo;	// Reset the pointer of arr to point to the tempo array
		}

		// Print the results
		cout << "You entered " << counter << " numbers: ";
		for (int i = 0; i < counter; i++) {
			cout << arr[i] << " ";
		}

		cout << endl;
		// Clear the input buffer of errors and old data in preparation for the next run of the program
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Try Again (Y/N)? ";

		cin.get(answer);

		// Clear the input buffer of errors and old data
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (toupper(answer) == 'Y');

	return 0;
}
