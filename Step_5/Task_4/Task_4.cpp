//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
// File: Task_4.cpp
// Summary: This program simulates a Rock, Paper, Scissors game.
// Version: 1.1
// Owner: Jesper Malmberg
//-----------------------------------------------------------------------
// Log: 2022-02-10 Created file
//-----------------------------------------------------------------------
// Preprocessor directives
#include <iostream>
#include<cstring>
#include <algorithm>
#include <iterator>
#include <ctime>

using namespace std;

// Enum Hand
enum Hand { Rock, Paper, Scissor };
// Prototype
bool gameOver(int, int);
void compareHands(Hand, Hand, int&, int&);

int main()
{
	char answer;					// Play again or not

	do {
		system("CLS");				// Clear the console
		cout << "STONE SCISSORS PAPPER" << endl;
		cout << "=====================" << endl;
		Hand playerSelection;		// The player selection
		Hand computerSelection;		// The computer selection
		int playerScore = 0;		// Players running score
		int computerScore = 0;		// Computers running score
		int inpt;
		
		srand(time(0));				// Seed the rand with current time

		// While the game is not over solicit input and compare
		while (!gameOver(playerScore, computerScore)) {
			cout << "Your choice(Rock = 0 / Paper = 1 / Scissors = 2) : ";
			cin >> inpt;

			playerSelection = Hand(inpt);
			computerSelection = Hand(rand() % 3 + 0);

			// Comparer hanads
			compareHands(playerSelection, computerSelection, playerScore, computerScore);
			cout << "Score (you - computer): " << playerScore << " - " << computerScore << endl;
		}

		// Clear the input buffer of errors and old data
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Play again? (Y/N)";
		cin.get(answer);
	} while (toupper(answer) == 'Y');
	
	return 0;
}

//----------------------------------------------------------------------
// gameOver(int, int)
// This function returns a boolean indication if the game is over
// Returns: bool
//----------------------------------------------------------------------
bool gameOver(int ps, int cs) {

	if (ps == 10) {
		cout << "You won with " << ps << "-" << cs << endl;
		return true;
	}
	if (cs == 10) {
		cout << "You lost with " << cs << "-" << ps << endl;
		return true;
	}
	return false;
}

//----------------------------------------------------------------------
// compareHands(Hand, Hand, pScore, cScore)
// This function compares the two input enums Hand and adds to the score
// of the winning hand
// Returns: void
//----------------------------------------------------------------------
void compareHands(Hand player, Hand computer, int &pScore, int &cScore) {
	// Print computer's selection
	switch (computer) {
		case Rock: cout << "Computer chose Rock" << endl;
			break;
		case Paper: cout << "Computer chose Paper" << endl;
			break;
		case Scissor: cout << "Computer chose Scissor" << endl;
			break;
	}
	// Check player's hand. The nested switch then checks the computers hand with the nested switches and prints who won and adds to the running score
	switch (player) {
		case Rock:	
			switch (computer) {
				case Rock: cout << "Equal!" << endl;
					break;
				case Paper: cout << "Computer won!" << endl;
					cScore++;
					break;
				case Scissor: cout << "You won!" << endl;
					pScore++;
					break;
			}
			break;
		case Paper:
			switch (computer) {
				case Rock: cout << "You won!" << endl;
					pScore++;
					break;
				case Paper: cout << "Equal!" << endl;
					break;
				case Scissor:  cout << "Computer won!" << endl;
					cScore++;
					break;
			}
			break;
		case Scissor:
			switch (computer) {
				case Rock:  cout << "Computer won!" << endl; 
					cScore++;
					break;
				case Paper: cout << "You won!" << endl; 
					pScore++;
					break;
				case Scissor: cout << "Equal!" << endl;
					break;
				}
			break;
	}
}
