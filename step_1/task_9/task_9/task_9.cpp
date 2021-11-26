//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
// File: Source.cpp
// Summary: This program calculates investements with interest
// Version: 1.1
// Owner: Jesper Malmberg
//-----------------------------------------------------------------------
// Log: 2021-11-19 Created file
//-----------------------------------------------------------------------
// Preprocessor directives
#include <iostream>
#include <iomanip>
using namespace std;
// Prototypes
void investmentGrowth();
int main() {
	char answer;
	do {
		investmentGrowth();
		cout << "One more time? (Y/N): ";
		cin >> answer;
	} while (answer == 'Y' || answer == 'y');
	return 0;
}
//-----------------------------------------------------------------
// void investmentGrowth
// Calculates the growth with interest over 4 years
//-----------------------------------------------------------------
void investmentGrowth() {
	double investment;				   // The initial investment
	double year1, year2, year3, year4; // The interest every year
	double investmentWithInterest;	   // The investement value after 4 years

	cout << "Enter the initial investment in SEK: ";
	cin >> investment;
	cout << "Enter percentage year 1: ";
	cin >> year1;
	cout << "Enter percentage year 2: ";
	cin >> year2;
	cout << "Enter percentage year 3: ";
	cin >> year3;
	cout << "Enter percentage year 4: ";
	cin >> year4;

	// Calculate the investment with compounding interest
	investmentWithInterest = investment * (1 + year1 / 100);
	investmentWithInterest *= (1 + year2 / 100);
	investmentWithInterest *= (1 + year3 / 100);
	investmentWithInterest *= (1 + year4 / 100);
	
	cout << fixed << setprecision(2) << "Your investment is now worth: " << investmentWithInterest << " SEK";
	cout << endl;
}


