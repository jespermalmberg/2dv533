//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
// File: Task_3.cpp
// Summary: This program demonstrates the use of structure TimeType
// Version: 1.1
// Owner: Jesper Malmberg
//-----------------------------------------------------------------------
// Log: 2022-02-04 Created file
//-----------------------------------------------------------------------
// Preprocessor directives
#include <iostream>
#include<cstring>
#include <algorithm>
#include <iterator>
#include <ctime>

using namespace std;

struct TimeType
{
	int hour;
	int min;
};

// Prototypes
int toMinutes(TimeType);
TimeType toTime(int);
TimeType timeDifference(TimeType, TimeType);
void print(TimeType);
TimeType dynamicTimes();

int main()
{
	// Demonstration of subtaskt a)
	int minutes;
	TimeType timeA = { 10, 15 };
	minutes = toMinutes(timeA);
	cout << minutes << " minutes" << endl; // Should write: 615 minutes

	// Demonstration of subtask b)
	int min = 124;
	TimeType time = toTime(min);
	print(time);
	cout << endl;

	// Demonstration of subtask c)
	TimeType timeB = { 10, 30 }, timeC = { 13, 20 }, difference;
	difference = timeDifference(timeB, timeC);
	print(difference);
	cout << endl;
	cout << endl;

	// Demonstration of subtask d)
	TimeType maxDiff = dynamicTimes();
	print(maxDiff);
	cout << endl;
	
	return 0;
}

//----------------------------------------------------------------------
// toMinutes(TimeType)
// This function returns the total minutes from TimeType struct
// Returns: int
//----------------------------------------------------------------------
int toMinutes(TimeType tp) {
	return tp.hour * 60 + tp.min;
}

//----------------------------------------------------------------------
// toTime(int)
// This function returns the hours and minutes in the form of TimeType
// Returns: TimeType
//----------------------------------------------------------------------
TimeType toTime(int min) {
	TimeType tp;
	tp.hour = min / 60;
	tp.min = min % 60;
	return tp;
}

//----------------------------------------------------------------------
// timeDifference(TimeType, TimeType)
// This function returns the difference of two times	
// Returns: TimeType
//----------------------------------------------------------------------
TimeType timeDifference(TimeType t1, TimeType t2) {
	int difference = toMinutes(t1) - toMinutes(t2);
	if (difference < 0) {
		difference = -difference;
	}
	return toTime(difference);
}

//----------------------------------------------------------------------
// dynamicTimes()
// This function returns the difference of two times, the largest and
// smallest of 200 random times	
// Returns: TimeType
//----------------------------------------------------------------------
TimeType dynamicTimes() {
	// Seed the randomizer
	srand(time(0));

	TimeType* times = new TimeType[200];	// Dynamic array with 200 timeTypes
	int* tempo = new int[200];				// Dynamic array with the timetype as minutes for sorting

	// Randomize time in minutes
	for (int i = 0; i < 200; i++) {
		tempo[i] = rand();
	}

	// Sort the minutes
	sort(tempo, tempo + 200);


	// Create TimeTypes
	for (int i = 0; i < 200; i++) {
		times[i] = toTime(tempo[i]);
	}

	// Calculate difference between first and last element in times
	TimeType tt = timeDifference(times[0], times[199]);

	// Delete dynamic arrays
	delete[]tempo;
	delete[]times;

	return tt;
}
//----------------------------------------------------------------------
// print(TimeType)
// This helper function prints a TimeType in the hh:mm format
//----------------------------------------------------------------------
void print(TimeType tp) {
	if (tp.hour < 10) {
		cout << "time 0" << tp.hour << ":";
	}
	else {
		cout << "time " << tp.hour << ":";
	}
	if (tp.min < 10) {
		cout << "0" << tp.min;
	}
	else {
		cout << tp.min;
	}
}
