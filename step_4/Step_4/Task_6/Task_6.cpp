//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
// File: Task_6.cpp
// Summary: This program stores and calculates stutents' average scores
// Version: 1.1
// Owner: Jesper Malmberg
//-----------------------------------------------------------------------
// Log: 2021-12-22 Created file
//-----------------------------------------------------------------------
// Preprocessor directives
#include <iostream>


using namespace std;
// Prototypes
void enterData(struct Student);
void printData(struct Student);
// Constants
const int QUIZZES = 2;
const int EXAMS = 2;
const int NUMBEROFSTUDENTS = 3;

// The datastructure Student holds information on a student
struct Student {
	int id;
	double quizzes[QUIZZES];
	double exams[EXAMS];
	double averageScore;
	char grade;

	double totalNumericScore() {

	}
};

int main()
{
	char answer;

	struct Student students[NUMBEROFSTUDENTS];

	//Student students[NUMBEROFSTUDENTS];

	do {
		system("CLS");			// Clear the console

		

		for (int i = 0; i < NUMBEROFSTUDENTS; i++) {
			cout << "Enter student number: " << endl;
			std::cin >> students[i].id;
			std::cin.clear();
			std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Enter two 10 point quizzes" << endl;
			std::cin >> students[i].quizzes >> students[i].quizzes;
			cout << "Enter the midterm and final exam grades. These are 100 point tests" << endl;
			std::cin >> students[i].exams >> students[i].exams;
		}

		for (int i = 0; i < NUMBEROFSTUDENTS; i++) {
			cout << students[i].exams[1] << endl;
			cout << students[i].exams[2] << endl;

		}
		
		









		cout << "Enter more students? (Y/N) ";
		std::cin.get(answer);
		// Clear the input buffer of errors and old data
		std::cin.clear();
		std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (toupper(answer) == 'Y');

	return 0;
}

void enterData(Student Stu) {


}
void printData(Student Stu) {

}

