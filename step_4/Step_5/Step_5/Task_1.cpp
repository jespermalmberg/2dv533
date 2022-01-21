//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
// File: Task_1.cpp
// Summary: This program removes whitespaces
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
		int* arr = new int[0];
		int a;

		cout << "Enter integer numbers to store (Stop by entering any non-numeric value):";
		cin >> a;
		while (!cin.fail()) {
			counter++;
			int* newArr = new int[sizeof(arr) + 1];
			cin >> a;
			arr = newArr;
			newArr[sizeof(newArr) - 1] = a;
			arr = newArr;
			delete(newArr);
		}

		cout << "You entered " << counter << "numbers: ";
		for (int i = 0; i < sizeof(arr); i++) {
			cout << arr[i];
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
