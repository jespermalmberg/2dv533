//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
// File: Task_8.cpp
// Summary: This program finds and prints all the prime numbers 2-100
// Version: 1.1
// Owner: Jesper Malmberg
//-----------------------------------------------------------------------
// Log: 2021-11-28 Created file
//-----------------------------------------------------------------------
// Preprocessor directives
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	// Outer loop goes through all numbers 2-100
	for (int i = 3; i <= 100; i++) {
		bool isPrime = true;	// Initialize to True until we can verify that i is not a prime
		// Inner loop checks if i is a prime
		for (int j = 2; j < i; j++) {
			// If we get a match, ie i divides with no rest on j break the loop
			if (i % j == 0) {
				isPrime = false;
				break;
			} 
		}
		// If i doesn't divide without rest on j we have a prime and print the answer
		if (isPrime) {
			cout << i << endl;
		}
	}
}
