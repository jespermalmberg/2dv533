//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
// File: Source.cpp
// Summary: This program calculates the wind chill factor.
// Version: 1.1
// Owner: Jesper Malmberg
//-----------------------------------------------------------------------
// Log: 2021-11-19 Created file
//-----------------------------------------------------------------------
// Preprocessor directives
#include <iostream>
#include <iomanip>
#include<cmath> // Used for math pow()

using namespace std;
// Prototypes
void windChillFactor();

int main() {
	char answer;
	do {
		windChillFactor();
		cout << "One more time? (Y/N): ";
		cin >> answer;
	} while (answer == 'Y' || answer == 'y');
	return 0;
}
//-----------------------------------------------------------------
// void windChillFactor()
// This function takes temperature in C and windspeed in m/s and
// calculates the wind chill factor
//-----------------------------------------------------------------
void windChillFactor() {
	double temperature; // Temperature in C
	double windSpeed;	// Windspeed in m/s
	double chillEffect; // The calculated chill effect

	cout << "Enter the temperature in C: ";
	cin >> temperature;
	cout << "Enter the windspeed in m/s: ";
	cin >> windSpeed;

	// This formula calculates the wind chill factor
	chillEffect = 13.126667 + 0.6215 * temperature - 13.924748 * pow(windSpeed, 0.16) + 0.4875195 * temperature * pow(windSpeed, 0.16);

		cout << fixed << setprecision(0) << temperature << " C and " << windSpeed << " m/s gives the perceived temperature " << chillEffect << " C";
		cout << endl;
}
