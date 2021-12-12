//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
// File: Task_6.cpp
// Summary: This program includes 4 basic arithmetic operations on
//			fractional numbers
// Version: 1.1
// Owner: Jesper Malmberg
//-----------------------------------------------------------------------
// Log: 2021-12-11 Created file
//-----------------------------------------------------------------------
// Preprocessor directives
#include <iostream>
#include <iomanip>

using namespace std;
// Function prototypes
void addition(int, int, int, int);
void subtraction(int, int, int, int);
void multiplication(int, int, int, int);
void division(int, int, int, int);
//void printFraction(int, int);
int gcdCalculator(int, int);

int main()
{
	char answer;											// Continue or stop program variable
	int numerator1, denominator1, numerator2, denominator2;	// The four numbers of the fraction
	char ignoreInput;										// Dummy variable to discard the '/' character
	int option;												// Variable for the selection of arithmetic operation
	
	do {
		printf("\033c"); // Resets the terminal window

		cout << "Enter the first fractional number (x/y): ";
		cin >> numerator1 >> ignoreInput >> denominator1;
		cout << "Enter the second fractional number (x/y): ";
		cin >> numerator2 >> ignoreInput >> denominator2;
		cout << endl;

		// Menu option
		cout << "Which aritmetic operation would you like to perform? Enter the number: " << endl;
		cout << "(1) Addition       " << numerator1 << "/" << denominator1 << " + " << numerator2 << "/" << denominator2 << endl;
		cout << "(2) Subtraction    " << numerator1 << "/" << denominator1 << " - " << numerator2 << "/" << denominator2 << endl;
		cout << "(3) Multiplication " << numerator1 << "/" << denominator1 << " * " << numerator2 << "/" << denominator2 << endl;
		cout << "(4) Division       " << numerator1 << "/" << denominator1 << " / " << numerator2 << "/" << denominator2 << endl;
		cin >> option;

		// Switch for the menu
		switch (option) {
			case 1:
				addition(numerator1,denominator1, numerator2, denominator2);
				break;
			case 2:
				subtraction(numerator1, denominator1, numerator2, denominator2);
				break;
			case 3:
				multiplication(numerator1, denominator1, numerator2, denominator2);
				break;
			case 4:
				division(numerator1, denominator1, numerator2, denominator2);
				break;
		}
		cout << endl;
		cout << "One more time (Y/N)?";
		cin >> answer;

	} while (toupper(answer) == 'Y');
	return 0;
}

//-----------------------------------------------------------------------
// addition()
// This function takes 4 integers representing to fractional numbers
// and calculates the sum of the two
//-----------------------------------------------------------------------
void addition(int num1, int den1, int num2, int den2) {
	int newNumerator = num1 * den2 + num2 * den1;
	int newDenominator = den1 * den2;

	int gCd = gcdCalculator(newNumerator, newDenominator);
	cout << "The sum of " << num1 << "/" << den1 << " + " << num2 << "/" << den2 << " = " << newNumerator / gCd << "/" << newDenominator /gCd;

}
//-----------------------------------------------------------------------
// subtraction()
// This method takes 4 integeres representing 2 fractional numbers
// and calculates the difference between the two
//-----------------------------------------------------------------------
void subtraction(int num1, int den1, int num2, int den2) {
	int newNumerator = num1 * den2 - num2 * den1;
	int newDenominator = den1 * den2;

	int gCd = gcdCalculator(newNumerator, newDenominator);
	cout << "The difference between " << num1 << "/" << den1 << " - " << num2 << "/" << den2 << " = " << newNumerator / gCd << "/" << newDenominator / gCd;
}

//-----------------------------------------------------------------------
// multiplication()
// This function takes 4 integers representing 2 fractional numbers
// and calculates the product of the two
//-----------------------------------------------------------------------
void multiplication(int num1, int den1, int num2, int den2) {
	int newNumerator = num1 * num2;
	int newDenominator = den1 * den2;

	int gCd = gcdCalculator(newNumerator, newDenominator);
	cout << "The product of " << num1 << "/" << den1 << " * " << num2 << "/" << den2 << " = " << newNumerator / gCd << "/" << newDenominator / gCd;
}

//-----------------------------------------------------------------------
// division()
// This function takes 4 integers representing 2 fractional numbers
// and calculates the quotient of the two
//-----------------------------------------------------------------------
void division(int num1, int den1, int num2, int den2) {
	int newNumerator = num1 * den2;
	int newDenominator = den1 * num2;

	int gCd = gcdCalculator(newNumerator, newDenominator);
	cout << "The quotient of " << num1 << "/" << den1 << " / " << num2 << "/" << den2 << " = " << newNumerator / gCd << "/" << newDenominator / gCd;
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
