//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
// File: Task_2.cpp
// Summary: This program calculatest the score of a dive
// Version: 1.1
// Owner: Jesper Malmberg
//-----------------------------------------------------------------------
// Log: 2021-12-19 Created file
//-----------------------------------------------------------------------
// Preprocessor directives
#include <iostream>
#include <cstdlib> // atoi()
#include <cctype> // isdigit()
using namespace std;
// Prototypes
bool isDifficultyOk(char dif[], int amount);

int main()
{
	// Constants
	const int MAXDIFFLENGTH = 100;
	const double MAXDIFFICULTY = 4.0;
	const double MAXSCORE = 10;

	double score[7];
	char dif[MAXDIFFLENGTH];

	double difficulty;

	bool diffOk = false;
	bool scoreOk;

	do {
		cout << "Enter the degree of difficulty for the dive (1.0 - 4.0) : ";

		cin.getline(dif, MAXDIFFLENGTH, '\n');

		diffOk = isDifficultyOk(dif, 3);
		if (!diffOk)
			cout << "Try again!" << endl;
	} while (!diffOk);


	//for (int i = 1; i <= 7; i++) {
	//	cout << "Enter score for judge " << i << " (0-10): ";
	//	
	//}
	//cout << difficulty;
	cout << "it works";
	return 0;
}

bool isDifficultyOk(char dif[], int amount) {

	if (!isdigit(dif[0]) || dif[1] != '.' || !isdigit(dif[2])) {
		return false;
	}
	int i = 0;
	while (dif[i] != '\0') {
		cout << i;
		i++;
	}

	return (1 <= i && i <= 3);
}