//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
// File: Task_4.cpp
// Summary: This program prints multiplication tables
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
void getTable();
int main() {

	getTable();
	return 0;
}
//-----------------------------------------------------------------
// void getTable()
// Prints a table with 1-15 multiplied by 1, 10, 100 and 1000
//-----------------------------------------------------------------
	void getTable() {
	cout << "Multiplication table" << endl;
	cout << "====================" << endl << endl;
	// Setup the basic table printout
	cout << setw(5) << "n" << setw(10) << "10*n" << setw(10) << "100*n" << setw(10) << "1000*n" << endl
	<< "-----------------------------------" << endl;
	// The table
	for (int x = 1; x <= 15; ++x) {
		cout << setw(5) << x*1 << setw(10) << x * 10 << setw(10) << x * 100 << setw(10) << x * 1000 << endl;
	}
}
