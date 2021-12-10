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
int heightEstimate(char sex, int hMother, int hFather);

int main()
{	
	char sex;
	int hMother;
	int hFather;
	char answer = 'Y';
	do {
		cout << "test"
		cout << "Enter the sex of the child (M/F): ";
		cin >> toupper(sex);
		switch (sex) {
		case "F":
			cout << "Enter the height of the MOTHER in cm: ";
			cin >> hMother;
			break;
		case "M":
			cout << "Enter the height of the FATHER in cm: ";
			cin >> hFather;
			break;
		default:
			cout << "Incorrect "
		}
		cout << "Enter the height of the Father in cm: ";
		

		cout << endl << "One more time (N/N)? ";
		cin >> answer;
	} while (toupper(answer) == 'Y');
	return 0;
}

//-------------------------------------------------------
// This function estimates the height of a child
// It takes the sex of the child, height of the father and
// the mother as input parameters
//-------------------------------------------------------
int heightEstimate(char sex, int hMother, int hFather) {
		
		Hmale_child = ((Hmother 13 / 12) + Hfather) / 2
		Hfemale_child = ((Hfather 12 / 13) + Hmother) / 2
}

