//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
// File: Task_1.cpp
// Summary: This program computes the volume of a cube with specified side
// Version: 1.1
// Owner: Jesper Malmberg
//-----------------------------------------------------------------------
// Log: 2021-12-06 Created file
//-----------------------------------------------------------------------
// Preprocessor directives
#include <iostream>
#include <cctype> // toupper
using std::cout;
using std::cin;
using std::endl;
// Prototypes
void getSide(double&); // Parameter passed as reference
void cubeVolume(double&, double); // Parameter passed as reference and as value
void printVolume(double);

int main()
{
	double side = 0.0, volume = 0.0;
	char answer = 'Y';
	cout << "Cubes" << endl;
	cout << "=====" << endl << endl;
	do
	{
		// Read side
		getSide(side);
		// Calculate volume
		cubeVolume(volume, side);
		// Print volume
		printVolume(volume);

		cout << endl << "One more time (Y/N)? ";
		cin >> answer;
	} while (toupper(answer) == 'Y');
	return 0;
}

//-----------------------------------------------------------------
// void getSide()
// Takes the input side length as parameter passed by reference
//-----------------------------------------------------------------
void getSide(double &side) {
	cout << "Enter the side length of a cube to be computed: ";
	cin >> side;
}

//-----------------------------------------------------------------
// void cubeVolume()
// Calculates the volume of a cube
// Takes side and volume as parameters. Side is passed as value and
// volume by reference
//-----------------------------------------------------------------
void cubeVolume(double &volume, double side) {
	volume = side * side * side;
}

//-----------------------------------------------------------------
// void printVolume()
// Prints the referenced argument to the console
//-----------------------------------------------------------------
void printVolume(double volume) {
	cout << "Volume of the cube is: " << volume << " volume units" << endl;
}