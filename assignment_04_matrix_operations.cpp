// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_SIZE = 10; // Fixed maximum size for array dimensions

// Function to print a matrix
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << setw(4) << matrix[i][j]; // setw(4) for alignment
        }
        cout << endl;
    }
}

// Function to read a matrix from the user
void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int& rows, int& cols, const string& matrixName) {
    cout << "Enter number of rows for " << matrixName << ": ";
    cin >> rows;
    cout << "Enter number of columns for " << matrixName << ": ";
    cin >> cols;

    if (rows <= 0 || rows > MAX_SIZE || cols <= 0 || cols > MAX_SIZE) {
        cout << "Error: Dimensions must be positive and not exceed " << MAX_SIZE << ".\n";
        exit(1); // Exit if dimensions are invalid
    }

    cout << "Enter elements for " << matrixName << ":\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// PART A: Transpose a Matrix
void transposeMatrix() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int rows, cols;

    readMatrix(matrix, rows, cols, "Original Matrix");

    cout << "\nOriginal Matrix:\n";
    printMatrix(matrix, rows, cols);

    cout << "\nTransposed Matrix:\n";
    // Transposed matrix will have cols x rows dimensions
    for (int j = 0; j < cols; ++j) {
        for (int i = 0; i < rows; ++i) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
}

// PART B: Add Two Matrices
void addMatrices() {
    int matrixA[MAX_SIZE][MAX_SIZE];
    int rowsA, colsA;
    readMatrix(matrixA, rowsA, colsA, "Matrix A");

    int matrixB[MAX_SIZE][MAX_SIZE];
    int rowsB, colsB;
    readMatrix(matrixB, rowsB, colsB, "Matrix B");

    if (rowsA != rowsB || colsA != colsB) {
        cout << "Error: Matrices must have the same dimensions for addition.\n";
        return;
    }

    int resultMatrix[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsA; ++j) {
            resultMatrix[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }

    cout << "\nMatrix A:\n";
    printMatrix(matrixA, rowsA, colsA);
    cout << "\nMatrix B:\n";
    printMatrix(matrixB, rowsB, colsB);
    cout << "\nSum Matrix (A + B):\n";
    printMatrix(resultMatrix, rowsA, colsA);
}

// PART C: Multiply Two Matrices
void multiplyMatrices() {
    int matrixA[MAX_SIZE][MAX_SIZE];
    int rowsA, colsA;
    readMatrix(matrixA, rowsA, colsA, "Matrix A");

    int matrixB[MAX_SIZE][MAX_SIZE];
    int rowsB, colsB;
    readMatrix(matrixB, rowsB, colsB, "Matrix B");

    if (colsA != rowsB) {
        cout << "Error: Number of columns in Matrix A must equal number of rows in Matrix B for multiplication.\n";
        return;
    }

    int resultRows = rowsA;
    int resultCols = colsB;
    int resultMatrix[MAX_SIZE][MAX_SIZE] = {0}; // Initialize with zeros

    // Perform multiplication
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            for (int k = 0; k < colsA; ++k) { // or rowsB, as they are equal
                resultMatrix[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    cout << "\nMatrix A:\n";
    printMatrix(matrixA, rowsA, colsA);
    cout << "\nMatrix B:\n";
    printMatrix(matrixB, rowsB, colsB);
    cout << "\nProduct Matrix (A x B):\n";
    printMatrix(resultMatrix, resultRows, resultCols);
}

int main() {
    int choice;
    do {
        cout << "\n--- Matrix Operations Menu ---\n";
        cout << "1. Transpose a Matrix\n";
        cout << "2. Add Two Matrices\n";
        cout << "3. Multiply Two Matrices\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                transposeMatrix();
                break;
            case 2:
                addMatrices();
                break;
            case 3:
                multiplyMatrices();
                break;
            case 4:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}


