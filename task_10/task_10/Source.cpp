//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
// File: Source.cpp
// Summary: This program calculates compounding interest over years
// Version: 1.1
// Owner: Jesper Malmberg
//-----------------------------------------------------------------------
// Log: 2021-11-19 Created file
//-----------------------------------------------------------------------
// Preprocessor directives
#include <iostream>
#include <iomanip>
#include <cmath> // For math pow()
using namespace std;
// Prototypes
void input();
void compoundInterest();
void print(double, double);

// Global Variables
const double INTEREST = 3;
double initialAmount;
double years;

int main() {
	char answer;
	do {
		input();
		compoundInterest();
		cout << "One more time? (Y/N): ";
		cin >> answer;
		cout << endl;
	} while (answer == 'Y' || answer == 'y');

	return 0;
}
//-----------------------------------------------------------------
// void input
// Takes console input for manipulation
//-----------------------------------------------------------------
void input() {
	cout << "COMPOUND INTEREST\n";
	cout << "==============\n";
	cout << "\n";
	cout << "Load initial amount: ";
	cin >> initialAmount;
	cout << "Load number of years: ";
	cin >> years;
	cout << endl;
}

//-----------------------------------------------------------------
// void compoundInterest
// Calculates the compounding interest over 4 years
//-----------------------------------------------------------------
void compoundInterest() {
	double capital; // The investment with compunding interest
	capital = initialAmount* pow((1 + INTEREST / 100), years);
	print(years, capital);
}

//-----------------------------------------------------------------
// void print
// Prints manipulated input to conosle
//-----------------------------------------------------------------
void print(double years, double capital) {
	cout << "The capital with " << INTEREST << " % interest rate and after " << 10 << " years will be: " << capital << " SEK";
	cout << endl;
}
