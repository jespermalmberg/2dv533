//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
// File: Task_3.cpp
// Summary: This program returns lowest common denominator
// 
// Version: 1.1
// Owner: Jesper Malmberg
//-----------------------------------------------------------------------
// Log: 2021-12-19 Created file
//-----------------------------------------------------------------------
// Preprocessor directives
#include <iostream>
#include <iomanip>

using namespace std;
// Function prototypes
int gcdCalculator(int num1, int num2);

// The datastructure fraction holds information on the numerator and denominator
struct Fraction {
	int numerator;
	int denominator;
};

int main()
{
	char answer;			// Continue or stop program variable
	Fraction f;				// The fractional number to be calculated


	do {
		printf("\033c");	// Resets the terminal window

		cout << "FRACTION CALCULATION" << endl;
		cout << "====================" << endl;
		cout << endl;			
		
		cout << "Enter the numerator : ";
		cin >> f.numerator;
		cout << "Enter the denominator : ";
		cin >> f.denominator;

		// If denominator is < 0
		if (f.denominator < 0) {
			f.numerator = -f.numerator;
			f.denominator = -f.denominator;
		}

		// Calculate the gcd
		int gcd = gcdCalculator(f.numerator, f.denominator);

		// Calculate the new fractional numbers base on gcd
		int n = f.numerator / gcd;
		int d = f.denominator / gcd;

		// the whole number plus remaining fraction is found by using % operator.
		cout << " The fraction can be abbreviated to : " << n << "/" << d << " = " << n / d << " " << n % d << "/" << d << endl;

		cout << "One more time? (Y/N) ";
		cin >> answer;
	} while (toupper(answer) == 'Y');
	return 0;
}

//-----------------------------------------------------------------------
// gcdCalculator()
// This helper function takes two integers and calculates the greatest common
// denominator. It returns the gcd or 1 if there is none.
//-----------------------------------------------------------------------
int gcdCalculator(int num1, int num2) {

	// If the fractional number is negative change it to positive in order to find gcd
	if (num1 < 0) {
		num1 = -num1;
	}
	if (num2 < 0) {
		num2 = -num2;
	}

	// Default value, if no common denominator, return 1
	int gcd = 1;

	for (int i = 1; i <= num1 && i <= num2; i++)
	{
		if (num1 % i == 0 && num2 % i == 0)
			gcd = i;
	}
	return gcd;
}
