// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================





#include <iostream>
#include <vector>
using namespace std;

// Function to calculate the sum of numbers in a vector
double calculateSum(const vector<double>& arr) {
    double sum = 0.0;
    for (double num : arr) {
        sum += num;
    }
    return sum;
}

// Function to calculate the average of numbers in a vector
double calculateAverage(const vector<double>& arr) {
    if (arr.empty()) {
        return 0.0;
    }
    return calculateSum(arr) / arr.size();
}

// Function to find the maximum number in a vector
double findMaximum(const vector<double>& arr) {
    if (arr.empty()) {
        return 0.0;
    }
    double maxVal = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

// Function to find the minimum number in a vector
double findMinimum(const vector<double>& arr) {
    if (arr.empty()) {
        return 0.0;
    }
    double minVal = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return minVal;
}

int main() {
    int n;
    cout << "How many numbers? ";
    cin >> n;

    if (n <= 0) {
        cout << "Error: N must be a positive integer." << endl;
        return 1;
    }

    vector<double> numbers(n);
    for (int i = 0; i < n; ++i) {
        cout << "Enter number " << i + 1 << ": ";
        cin >> numbers[i];
    }

    cout << endl << "Results:" << endl;
    cout.precision(1);
    cout << fixed;
    cout << "Sum:     " << calculateSum(numbers) << endl;
    cout << "Average: " << calculateAverage(numbers) << endl;
    cout << "Maximum: " << findMaximum(numbers) << endl;
    cout << "Minimum: " << findMinimum(numbers) << endl;

    return 0;
}