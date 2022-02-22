//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
// File: Task_5.cpp
// Summary: 
// Version: 1.0
// Owner: Jesper Malmberg
//-----------------------------------------------------------------------
// Log: 2022-02-12 Created file
//-----------------------------------------------------------------------
// Preprocessor directives
#include <iostream>
#include <random>
#include <iomanip>
using namespace std;

const double R = 100; // Radius of the circle (=square side) is determined here
struct Coord // Data representation of a point where the arrow hits
{
	double x, y;
};
// Prototype
Coord throwArrow();
bool below(Coord);
void throwSeries(double);

int main() {

	// Print header
	cout << "     n     pi     Rel. fault" << endl;
	cout << "------|----------|-------" << endl;
	
	// Throw series
	for (int i = 100; i < 10100; i = i + 100) {
		throwSeries(i);
	}

	return 0;
}

//----------------------------------------------------------------------
// throwArrow()
// This function simulates the throw of an arrow and returns an x and y
// coordinate
// Returns: Coord
//----------------------------------------------------------------------
Coord throwArrow() {

	std::random_device rd;	// Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
	std::uniform_real_distribution<> dis(0.0, 100.0); // 

	return Coord{dis(gen),dis(gen)};
}

//----------------------------------------------------------------------
// below(Coord)
// This function checks if a resulting arrow throw ends up below the arc
// with radius R
// Returns: boolean
//----------------------------------------------------------------------
bool below(Coord cord) {
	// Check if below the arc
	if (pow(cord.x, 2) + pow(cord.y, 2) < pow(R, 2)) {
		return true;
	}
	return false;
}


//----------------------------------------------------------------------
// throwSeries(double)
// This function simulates a series of throws n, then calculates pi and 
// compares it with a constant pi and prints the results to the console
// Returns: void
//----------------------------------------------------------------------
void throwSeries(double n) {

	Coord c;
	const double Pi = 4 * atan(1.0);	// PI Constant
	double belowArc = 0;				// Number of arrows inside the arc
	double piCalculated;				// The calculated pi
	double relFault;					// Relative fault in %

	// Throw the arrow n times and record how many below the arc
	for (int i = 0; i < n; i++) {
		c = throwArrow();
		if (below(c)) {
			belowArc++;
		}
	}
	// Calculate pi and relative fault
	piCalculated = (belowArc * 4) / n;
	relFault = (piCalculated - Pi) / Pi * 100;

	// Print the result to the console
	cout << fixed << setw(6) << right << setprecision(0) << n;
	cout << fixed << right << setw(11) << setprecision(5) << piCalculated;
	cout << fixed << right << setw(8) << setprecision(1) << relFault << endl;
}
