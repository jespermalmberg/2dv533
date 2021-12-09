//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
// File: Task_3.cpp
// Summary: This program increases x wit the power of y
// Version: 1.1
// Owner: Jesper Malmberg
//-----------------------------------------------------------------------
// Log: 2021-12-09 Created file
//-----------------------------------------------------------------------
// Preprocessor directives
#include <iostream>;

using namespace std;
// Prototypes
long power(long base, long exp = 2); // Default value for exp is declared in Prototype

int main()
{
	for (int i = 0; i < 10; i++) {
		cout << power(2, i) << " "; // prints 2 raised to the power of i
	}

	cout << endl;
	cout << power(3) << endl; // will print 9
	cout << power(4) << endl; // will print 16
	cout << power(5) << endl; // will print 25
	return 0;
}

//-----------------------------------------------
// long power() this function takes a long number
// and raises it by the power of defined exp which 
// defaults to 2
//-----------------------------------------------
long power(long base, long exp) {
	long result = base;
	for (int i = 0; i < exp; i++) {
		result = result * base;
	}
	return result;
}
