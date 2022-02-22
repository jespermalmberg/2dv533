//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
// File: Task_5.cpp
// Summary: 
// Version: 1.0
// Owner: Jesper Malmberg
//-----------------------------------------------------------------------
// Log: 2022-02-12 Created file
//-----------------------------------------------------------------------
// Preprocessor directives
#include <iostream>
#include <cstring>
using namespace std;

const int BUFLEN = 100; // Max length of reading buffer

void sort(char* friendList[], int n); // n is the number of elements
void print(char* friendList[], int n); // n is the number of elements
void terminate(char* friendList[], int n); // n is the number of elements
const int AMOUNT = 5;
int main() {

	char* friends[AMOUNT]; // Dynamic array with AMOUNT pcs of string pointers
	char buff[BUFLEN] = { "" }; // Creates a string buffer (null terminated)
	int count = 0;
	while (count < AMOUNT) // enter AMOUNT number of friends
	{
		cout << "Name a friend: ";
		cin.getline(buff, BUFLEN); // Temporary reading into string buffer
		friends[count] = new char[strlen(buff) + 1]; // Add dynamic char array to friends

		// Add the characters
		for (int i = 0; i < strlen(buff); i++) {
			friends[count][i] = buff[i];
		}
		// Add null terminator
		friends[count][strlen(buff)] = '\0';
		++count;
	}
	sort(friends, count); // Sorts the ‘count’ strings
	print(friends, count); // Prints the ‘count’ first names
	terminate(friends, count); // Releases all allocated memory space

	return 0;
}

//----------------------------------------------------------------------
// sort(char*, int)
// This function sort the strings in accordance with strcmp logic
// Returns: void
//----------------------------------------------------------------------
void sort(char* friendList[], int n) {
	char* tempo;

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (strcmp(friendList[j - 1], friendList[j]) > 0) {
				tempo = friendList[j - 1];
				friendList[j - 1] = friendList[j];
				friendList[j] = tempo;
			}
		}
	}
}

//----------------------------------------------------------------------
// print(char*, int)
// This function prints the sorted names
// Returns: void
//----------------------------------------------------------------------
void print(char* friendList[], int n) {
	
	// Print each char
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < strlen(friendList[i]); j++) {
			cout << friendList[i][j];
		}
		cout << " ";
	}
}

//----------------------------------------------------------------------
// terminate(char*, int)
// This function frees up the allocated memory for friendList
// Returns: void
//----------------------------------------------------------------------
void terminate(char* friendList[], int n) {

	// Delete the number of dynamic char arrays
	for (int i = 0; i < n; i++) {
		delete [] friendList[i];

	}
	// Remove reference to friendList
	friendList = nullptr;
	delete[] friendList;
}
