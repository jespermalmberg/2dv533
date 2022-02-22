//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
// File: Task_2.cpp
// Summary: THIS IS AN IMPROVEMENT OF ANOTER PROJECT
// Version: 1.1
// Owner: Jesper Malmberg
//-----------------------------------------------------------------------
// Log: 2022-02-02 Created file
//-----------------------------------------------------------------------
// Preprocessor directives
#include <iostream>
#include <ctime>
using namespace std;
enum Coin { Tails, Heads };
int main()
{
	int frequency0 = 0, frequency1 = 0;
	Coin face;	
	// Move the call to srand() outside the scope of the for loop in order to get the same seed value for all calls to rand()
	// The psuedo random generator should only be seeded once, seeding it 10 times within short time period is likely the reason
	// for the same random numbers beeing generated.
	srand(time(0));

	for (int counter = 1; counter <= 10; ++counter)
	{
		face = Coin(rand() % 2);
		cout << rand() << " ";
		switch (face)
		{
		case Tails: ++frequency0;
			break;
		case Heads: ++frequency1;
			break;
		}
	}
	cout << "Tails were rolled " << frequency0 << " times" << endl;
	cout << "Heads were rolled " << frequency1 << " times" << endl;
	cin.get();
	return 0;
}