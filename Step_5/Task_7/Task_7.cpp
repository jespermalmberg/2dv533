//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
// File: Task_7.cpp
// Summary: This program populates two matrixes and caluclates the product
// after multiplication
// Version: 1.0
// Owner: Jesper Malmberg
//-----------------------------------------------------------------------
// Log: 2022-02-22 Created file
//-----------------------------------------------------------------------
// Preprocessor directives
#include <iostream>
#include <iomanip>

using namespace std;

const int MAXDIM = 5; // max number of rows and columns supported by program
typedef double Matrix[MAXDIM][MAXDIM];

// Prototype
void setUpMatrix(Matrix M, int &row, int &col);
void readMatrix(Matrix M, int row, int col);
void multMatrix(const Matrix A, const Matrix B, Matrix C, int m, int n, int p);
void printMatrix(const Matrix M, int row, int col);

int main() {

	char answer;

	do {
		system("CLS");				// Clear the console
	cout << "Matrix manipulation" << endl;
	cout << "===================" << endl;
	cout << endl;

	// The three matrixes
	Matrix A;
	Matrix B;
	Matrix C;

	// The three variables representing rows and columns for the three matrixes
	int row_m = 0;
	int col_n= 0;
	int colRow_p = 0;

	// Enter dimensions and values of Matrix A
	cout << "Enter dimension of matrix A (row/col) with space between: ";
	setUpMatrix(A, row_m, colRow_p);
	cout << "Enter matrix A in free format:" << endl;
	readMatrix(A, row_m, colRow_p);

	// Enter dimensions and values of Matrix B
	cout << "Enter dimension of matrix B (row/col) with space between: ";
	setUpMatrix(B, colRow_p, col_n);
	cout << "Enter matrix B in free format:" << endl;
	readMatrix(B, colRow_p, col_n);
	
	// Multiply the two matrices
	multMatrix(A, B, C, row_m, col_n, colRow_p);

	// Print the result
	printMatrix(C, row_m, col_n);

	cout << "One more time (Y/N)?: ";

	// Clear the input buffer of errors and old data
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cin.get(answer);

	// Clear the input buffer of errors and old data
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (toupper(answer) == 'Y');

	return 0;
}

//----------------------------------------------------------------------
// setupMatrix(Matrix, int, int)
// This function takes user inputs from the console to setup a matrix
// Returns: void
//----------------------------------------------------------------------
void setUpMatrix(Matrix M, int& row, int& col) {
	while (true) {
		cin >> col;
		if (cin.peek() == '\n') {
			break;
		}
		row = col;
	}
	M[row][col];
}

//----------------------------------------------------------------------
// readMatrix(Matrix, int, int)
// This function takes user inputs from the console to populate a matrix
// Returns: void
//----------------------------------------------------------------------
void readMatrix(Matrix M, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> M[i][j];
		}
	}
}

//----------------------------------------------------------------------
// multMatrix(Matrix, Matrix, Matrix, int, int, int)
// This function multiplies two matrixes and puts the result in a third
// Returns: void
//----------------------------------------------------------------------
void multMatrix(const Matrix A, const Matrix B, Matrix C, int m, int n, int p) {
	
	// Initialize the new C matrix with zeroes
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
		{
			C[i][j] = 0;
		}
	
	// Triple nested loop to calculate the product of each row and col
	for (int h = 0; h < m; h++) {
		for (int i = 0; i < p; i++) {
			for (int j = 0; j < n; j++) {
				C[h][i] += A[h][j] * B[j][i];
			}
		}
	}
}

//----------------------------------------------------------------------
// printMatrix(Matrix, int, int)
// This function prints the matrix in a tabular form to the console
// Returns: void
//----------------------------------------------------------------------
void printMatrix(const Matrix M, int row, int col) {
	cout << "----------------------------------------" << endl;
	cout << "ANSWER" << endl;
	cout << endl;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << fixed << setw(10) << right << setprecision(1) << M[i][j];
		}
		cout << endl;
	}
	cout << endl;
}
