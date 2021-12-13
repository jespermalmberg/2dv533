//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
// File: Task_7.cpp
// Summary: This program checks the various properties of entered dates
// Version: 1.1
// Owner: Jesper Malmberg
//-----------------------------------------------------------------------
// Log: 2021-12-11 Created file
//-----------------------------------------------------------------------
// Preprocessor directives
#include <iostream>
#include <iomanip>

using namespace std;
// Function prototypes
bool leapYear(int);
int daysInMonth(int, int);
int tomorrow(int);

int main()
{
	char answer;	// Variable to keep program running
	int selection;	// Selection from the menu
	int year;		// Year as input by user
	int month;		// Month as input by user
	int date;		// Day/Date as input by user

	do {
		printf("\033c"); // Resets the terminal window

		cout << "What would you like to do?" << endl;
		cout << "(1) Check if leap year" << endl;
		cout << "(2) Check number of days in a month" << endl;
		cout << "(3) Check tomorrow's date" << endl;
		cin >> selection;

		switch (selection) {
		case 1:
			cout << "Enter a year: ";
			cin >> year;
			if (leapYear(year))
				cout << "This is a leap year!" << endl;
			else
				cout << "This is not a leap year!" << endl;
			break;
		case 2:
			cout << "Enter the year and month with a space between (2004 5)" << endl;
			cin >> year >> month;
			cout << "The number of days in this month is: " << daysInMonth(year, month);
			break;
		case 3:
			cout << "Enter a date on the form YYYYMMDD: ";
			cin >> date;
			cout << "Tomorrow it is: " << tomorrow(date);
			break;
		}

		cout << endl << "One more time (Y/N)? ";
		cin >> answer;
	} while (toupper(answer) == 'Y');
	return 0;
}

//-----------------------------------------------------------------------
// leapYear()
// This function takes a year as an input parameter and returns true or
// false depending if said year is a leapyear
//-----------------------------------------------------------------------
bool leapYear(int year) {
	if(year % 4 == 0 && year % 100 != 0) {
		return true;
	}
	else if(year % 400 == 0) {
		return true;
	}
	// Default return
	return false;
}

//-----------------------------------------------------------------------
// daysInMonth()
// This function takes the year abd month as integers and returns the
// number of days in the specified month
//-----------------------------------------------------------------------
int daysInMonth(int year, int month) {
	// April June September and November has 30 days
	if (month == 4 || month == 6 || month == 9 || month == 11) {
		return 30;
	} 
	// Check if February
	if (month == 2) {
		// If also leapyear
		if (leapYear(year)) {
			return 29;
		}
		else {
			return 28;
		}
	}
	// All other months
	return 31;
}

//-----------------------------------------------------------------------
// tomorrow()
// This function takes a date in the format YYYYMMDD and returns tomorrow's
// date
//-----------------------------------------------------------------------
int tomorrow(int date) {
	// Split date into Year, Month, Day
	int day = date % 100;
	int month = date / 100 % 100;
	int year = date / 10000;

	// If it's the last day of the month
	if (day == daysInMonth(year, month)) {

		// Check if month is December
		if (month == 12) {
			return (year + 1) * 10000 + 1 * 100 + 1;
		}
		// Any other month than December
		return year * 10000 + (month + 1) * 100 + 1;
	}
	// Default return, if it's not the last day of the month
	return year * 10000 + month * 100 + day + 1;
}
