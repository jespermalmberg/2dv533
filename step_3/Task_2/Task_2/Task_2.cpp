//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
// File: Task_2.cpp
// Summary: This program converts Farenheit to Celcius
// Version: 1.1
// Owner: Jesper Malmberg
//-----------------------------------------------------------------------
// Log: 2021-12-06 Created file
//-----------------------------------------------------------------------
// Preprocessor directives
#include <iostream>
#include <iomanip>
#include <cctype> // toupper
using namespace std;
// Prototypes
bool farenheitToCelsius(double,double &);

int main()
{
	double farenheit, celsius;
	bool aboveZero;
	char answer = 'Y';
	cout << "Temperature conversion" << endl;
	cout << "======================" << endl << endl;
	do
	{
		// Take the input
		cout << "Enter temperature in Fahrenheit : ";
		cin >> farenheit;
		// Make the conversion
		aboveZero = farenheitToCelsius(farenheit, celsius);
		cout << setprecision(3) << celsius << " degrees Celcius." << endl;
		// using std::boolalpha do print true/false instead of 1 or 0
		cout << "Boolean value returned by the conversion function is: " << boolalpha << aboveZero << endl;

		cout << endl << "One more time (Y/N)? ";
		cin >> answer;
	} while (toupper(answer) == 'Y');
	return 0;
}

//-----------------------------------------------------------------
// void farenheitToCelcius()
// Converts Farenheit to Celcius and returns True if above 0 C
//-----------------------------------------------------------------
bool farenheitToCelsius(double farenheit, double& celsius) {
	celsius = (farenheit - 32) * 5/9;
	if (celsius > 0) {
		return true;
	}
	return false;
}
