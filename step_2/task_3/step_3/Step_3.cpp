//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
// File: Step_3.cpp
// Summary: This program calculates the product of all odd integers 1-15
// Version: 1.1
// Owner: Jesper Malmberg
//-----------------------------------------------------------------------
// Log: 2021-11-26 Created file
//-----------------------------------------------------------------------
// Preprocessor directives
#include <iostream>
#include <iomanip>
using namespace std;
// Prototypes
void intProduct();
int main() {

	intProduct();
	return 0;
}
//-----------------------------------------------------------------
// void intProduct()
// Calculates the product of all odd integers 1-15
//-----------------------------------------------------------------
void intProduct() {
	int x = 0;
	int product = 1;
	// Iterate 15 times
	while (x < 16) {
		// Check if number is odd
		if (x % 2 != 0) {
			product = product * x;
		}
		x++; // Increase x by 1 for next iteration
	}
	cout << "The product of all odd integers 1-15 is: " << product;
}
