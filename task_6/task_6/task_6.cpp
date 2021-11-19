//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
// File: Source.cpp
// Summary: This program calculates the power vs dB increase
// Version: 1.1
// Owner: Jesper Malmberg
//-----------------------------------------------------------------------
// Log: 2021-11-18 Created file
//-----------------------------------------------------------------------
// Preprocessor directives
#include <iostream>
#include <iomanip>
using namespace std;
// Prototypes
void dBCalculation();
int main() {
	char answer;
	do {
		dBCalculation();
		cout << "One more time? (Y/N): ";
		cin >> answer;
	} while (answer == 'Y' || answer == 'y');
	return 0;
}
//-----------------------------------------------------------------
// void dBCalculation()
// Calculates the decibel and level increase when increassing power
//-----------------------------------------------------------------
void dBCalculation() {

	double p0, p1, dB;  // p0 is reference W, p1 is incresed W, dB is decibel.
	int level;			// The sound level increase.

	cout << "POWER CALCULATIONS" << "\n";
	cout << "==================" << "\n";
	cout << "Sound Power P0: ";
	cin >> p0;
	cout << "Increased Sound Power P1: ";
	cin >> p1;
	cout << "==================" << endl;
	// Make sure the incresed power is larger than the reference power
	if (p0 > p1) {
		cout << "Please enter a P1 that is larger than P0";
	}
	else {
		dB = 10 * log10(p1 / p0);
		level = dB / 3;
		cout << "A change in power from " << fixed << setprecision(1) << p0 << " to " << p1 << " corresponds to " << dB << " dB" << endl;
		cout << "That is, " << level << " level of 3 dB";
	}
	cout << endl;
}
