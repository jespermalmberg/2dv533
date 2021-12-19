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

using namespace std;
// Prototypes
void sortArray(int size, double arr[]);
double calculateScore(double arr[], double level);

int main()
{
	// Constants
	const double MAXDIFFICULTY = 4.0;
	const double MAXSCORE = 10;

	double score[7];		// Array to store the scores
	double difficulty;		// The level of difficulty entered

	bool diffOk = false;	// Is correct value entered
	bool scoreOk;			// Is correct score entered

	do {
		cout << "Enter the degree of difficulty for the dive (1.0 - 4.0) : ";

		cin >> difficulty;
		
		if (difficulty <= MAXDIFFICULTY) {
			diffOk = true;
		}
		if (!diffOk)
			cout << "Try again!" << endl;
		// Keep asking to enter level of difficulty until a correct value is entered
	} while (!diffOk);

	// Add the individual judges' scores
	for (int i = 0; i < 7; i++) {
		double temp;
		scoreOk = false;

		do {
			cout << "Enter score for judge " << i + 1 << " (0 - 10) : ";
			cin >> temp;
			if (temp >= 0 && temp <= MAXSCORE) {
				score[i] = temp;

				scoreOk = true;
			}
			if (!scoreOk) {
				cout << "Try again!" << endl;
			}
			// Keep asking to enter score until correct value entered
		} while (!scoreOk);
	}

	// Sort array and print to terminal
	sortArray(7, score);
	cout << endl;
	cout << "The diver's final score is: " << calculateScore(score, difficulty) << endl;

	return 0;
}

//-----------------------------------------------------------------------
// void sortArray(int size, double arr[])
// Sorts the specified array in ascending order
// 
// int size - the size of the array
// double arr[] - the specified array
//-----------------------------------------------------------------------
void sortArray(int size, double arr[]) {
	double temp; // Temporary score
	int i, j;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size - 1; j++) {
			if (arr[j] > arr[i]) {
				temp = arr[i]; // swap the scores
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

//-----------------------------------------------------------------------
// double calculateScore(double arr[], double level)
// Calculates the score as follows; largest and smallest score disregarded
// the sum of the others are added together, multiplied by level and 0.6
// 
// double arr[] - the specified array
// double level - the specified level of dificulty
//-----------------------------------------------------------------------
double calculateScore(double arr[], double level) {
	double sumOfJudges = 0;
	// Take only the mid 5 numbers ie not index 0 or 6
	for (int i = 1; i < 6; i++) {
		sumOfJudges += arr[i];
	}
	return sumOfJudges * level * 0.6;
}
