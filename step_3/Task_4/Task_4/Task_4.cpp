//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
// File: Task_4.cpp
// Summary: This program estimates the height of a child with input parameters
// of the father and the mother
// Version: 1.1
// Owner: Jesper Malmberg
//-----------------------------------------------------------------------
// Log: 2021-12-10 Created file
//-----------------------------------------------------------------------
// Preprocessor directives
#include <iostream>
#include <cctype>

using namespace std;
// Prototypes
int heightEstimate(char sex, double hMother, double hFather);

int main()
{
	char sex;
	double hMother;
	double hFather;
	char answer = 'Y';
	do {
		cout << "Enter the sex of the child (M/F): ";
		cin >> sex;

		cout << "Enter the height of the MOTHER in cm: ";
		cin >> hMother;
		cout << "Enter the height if the FATHER in cm: ";
		cin >> hFather;
		cout << "The estimated height of the child is " << heightEstimate(sex, hMother, hFather) << " cm.";
		cout << endl;

		cout << endl << "One more time (Y/N)? ";
		cin >> answer;
	} while (toupper(answer) == 'Y');
	return 0;
}

//-------------------------------------------------------
// This function estimates the height of a child
// It takes the sex of the child, height of the father and
// the mother as input parameters
//-------------------------------------------------------
int heightEstimate(char sex, double hMother, double hFather) {

	if (toupper(sex) == 'F') {
		return ((hMother * 13 / 12) + hFather) / 2;

	}
	if (toupper(sex) == 'M') {
		return ((hFather * 12 / 13) + hMother) / 2;
	}
}
