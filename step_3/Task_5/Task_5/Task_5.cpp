//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
// File: Task_5.cpp
// Summary: This program calculates payments with different discounts
// Version: 1.1
// Owner: Jesper Malmberg
//-----------------------------------------------------------------------
// Log: 2021-12-10 Created file
//-----------------------------------------------------------------------
// Preprocessor directives
#include <iostream>
#include <iomanip>


using namespace std;
// Function prototypes
void print(double sum, double discountKr);
void load(double &sum);
double discount(double sum);

int main()
{
	double sum = 0.0, discountKr = 0.0;
	char answer;
	do {
		printf("\033c"); // Resets the terminal window

		cout << "Discount" << endl;
		cout << "======" << endl << endl;
		// Load the input
		load(sum);

		discountKr = sum * discount(sum) / 100;
		
		// The sum after discount is taken out 
		sum = sum - discountKr;

		// Print to the terminal
		print(sum, discountKr);

		cout << endl << "One more time (Y/N)? ";
		cin >> answer;
	} while (toupper(answer) == 'Y');
	return 0;
}

//-----------------------------------------------------------------------
// print() This function prints the results to the terminal window
// It rounds the double to the nearest value
//-----------------------------------------------------------------------
void print(double sum, double dKr) {
	cout << fixed << setprecision(2);
	cout << "--------------------------------" << endl;
	cout.width(24); cout << left << "Discount       : " << right << round(dKr) << endl;
	cout.width(24); cout << left << "Net sum        : " << right << round(sum) << endl;
	cout << "--------------------------------";
}void load(double &sum) {	cout << "Enter the sum: ";	cin >> sum;}double discount(double sum) {	if (sum <= 500) {		return 0;	}	if (sum > 500 && sum <= 1000) {		return 5;	}	if (sum > 1000 && sum <= 5000) {		return 10;	}	else {		return 15;	}}