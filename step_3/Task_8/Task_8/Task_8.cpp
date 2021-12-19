//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
// File: Task_8.cpp
// Summary: This is a simple dice game
// Version: 1.1
// Owner: Jesper Malmberg
//-----------------------------------------------------------------------
// Log: 2021-12-12 Created file
//-----------------------------------------------------------------------
// Preprocessor directives
#include <iostream>
#include <iomanip>

using namespace std;
// Function prototypes
int humanTurn(int);
int computerTurn(int);
int rollDice();

int main()
{
	char answer;				// Variable to keep program running
	int humanTotalScore = 0;	// Initialize at zero
	int computerTotalScore = 0;	// Initialize at zero
	char selection;
	char roll;

	do {
		printf("\033c"); // Resets the terminal window

		cout << "Welcome to the Game of Dice Thrones! It's your turn! Enter 'r' to roll. ";
		cin >> selection;

		do {
			humanTotalScore = humanTurn(humanTotalScore);
			cout << "You rolled" << 3 << endl;
			cout << "Your score this round is: " << 3 << endl;
			cout << "If you hold, your total score would be: " << 3 << endl;
			cout << "Press 'h' to hold or 'r' to roll again.";
			cin >> selection;

		} while (toupper(selection) == 'R');

		cout << endl << "One more time (Y/N)? ";
		cin >> answer;
	} while (toupper(answer) == 'Y');
	return 0;
}

int humanTurn(int humanTotalScore) {
	int currentScore = 0;
	int diceRoll = rollDice();

	currentScore += diceRoll;
	humanTotalScore += diceRoll;
	cout << "You rolled " << diceRoll << endl;
	cout << "Yout score this round is " << currentScore << endl;
}

int computerTurn(int computerTotalScore) {
	return 1;
}

int rollDice() {
	return rand() % 6 + 1;
}