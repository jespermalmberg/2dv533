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

// Constants
const int QUIZZES = 2;
const int EXAMS = 2;
const int NUMBEROFSTUDENTS = 3;

// The datastructure Student holds information on a student
struct Student {
	int id;						// The id of the Student
	double quizzes[QUIZZES];	// An array with 2 quiz results
	double exams[EXAMS];		// An array with 2 exam results
	double averageScore;		// The average score
	char grade;					// Final grade

	// Calculates the average or total score as well as the final grade
	// Total score(average score) is calculated as follows:
	// Final exam (exams[1]) = 50%
	// Midterm exam (exams[0]) = 25%
	// Average of the two quizzes = 25%
	// Grade >= 90 = A, 90 >= 80 = B, 80 >= 70 = C, 70 >= 60 = D, <60 = F
	void totalNumericScore() {
		double examWorth = exams[1] * 0.5  + exams[0] * 0.25;
		double quizWorth = (quizzes[0] + quizzes[1]) / 2 * 10 * 0.25;
		averageScore = examWorth + quizWorth;
		if (averageScore >= 90) {
			grade = 'A';
		}
		else if (averageScore < 90 && averageScore >= 80) {
			grade = 'B';
		}
		else if (averageScore < 80 && averageScore >= 70) {
			grade = 'C';
		}
		else if (averageScore < 70 && averageScore >= 60) {
			grade = 'D';
		}
		else if (averageScore < 60) {
			grade = 'F';
		}
	}
};

// Prototypes
void enterData(Student&);
void printData(Student);

int main()
{
	char answer;

	struct Student students[NUMBEROFSTUDENTS];

	//Student students[NUMBEROFSTUDENTS];

	do {
		system("CLS");			// Clear the console

		// Enter the data tabout each student's quizzes and exams
		for (Student& stu : students) {
			enterData(stu);
		}

		// Print all student records
		for (Student stu : students) {
			stu.totalNumericScore();
			printData(stu);
			cout << endl;
		}

		cout << "Enter more students? (Y/N) ";
		// Clear the input buffer of errors and old data
		std::cin.clear();
		std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin.get(answer);
		// Clear the input buffer of errors and old data
		std::cin.clear();
		std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (toupper(answer) == 'Y');

	return 0;
}

//-----------------------------------------------------------------------
// void enterData(Student&)
// Enter the record of a student
// Parameter Student is passed by reference to relevant student structure
//-----------------------------------------------------------------------
void enterData(Student& stu) {
	cout << "Enter the student number: ";
	cin >> stu.id;
	cout << "Enter two 10 point quizzes" << endl;
	cin >> stu.quizzes[0] >> stu.quizzes[1];
	cout << "Enter the midterm and final exam grades. These are 100 point tests" << endl;
	std::cin >> stu.exams[0] >> stu.exams[1];
}

//-----------------------------------------------------------------------
// void printData(Student)
// Prints the record of all students scores, total score and grade
//-----------------------------------------------------------------------
void printData(Student stu) {
	cout << "The record for student number : " << stu.id << endl;
	cout << "The quiz grades are : " << stu.quizzes[0] << " " << stu.quizzes[1] << endl;
	cout << "The midterm and exam grades are: " << stu.exams[0] << " " << stu.exams[1] << endl;
	cout << "The total numeric score is : " << stu.averageScore << endl;
	cout << "and the letter grade assigned is: " << stu.grade << endl;
}
