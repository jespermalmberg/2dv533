//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
// File: Source.cpp
// Summary: This program calculates the remaining traveltime while driving
// Version: 1.1
// Owner: Jesper Malmberg
//-----------------------------------------------------------------------
// Log: 2021-11-15 Created file
//-----------------------------------------------------------------------
// Preprocessor directives
#include <iostream>
#include <iomanip>
using namespace std;
// Prototypes
void travelTimeCalculation();
int main() {
	char answer;
	do {
		travelTimeCalculation();
		cout << "Calculate one more time? (Y/N): ";
		cin >> answer;
	} while (answer == 'Y' || answer == 'y');
	return 0;
}
//-----------------------------------------------------------------
// void travelTimeCalculation()
//-----------------------------------------------------------------
void travelTimeCalculation()
{
	double miles = 0;			// The remaining travel distance in Swedish miles (1 mile = 10km).
	double averageSpeed = 0;	// The average speed for the remiander of the trip.

	cout << "Enter remaining travel distance in Swedish miles: ";
	cin >> miles;
	cout << "Enter the average speed in km/h: "; 
	cin >> averageSpeed;

	double travelTime = miles * 10 * 60 / averageSpeed;
	int hours = travelTime / 60;
	int min = travelTime + 0.5; // Add 0.5 in order to get correct rounding of integers.
	int minutes = min % 60;


	//cout << fixed << showpoint << setprecision(2);
	cout << "Remaining travel time: " << hours <<" hours and " << minutes << " minutes." << endl;
}
