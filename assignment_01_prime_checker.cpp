// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 1
// =============================================================================
//
// TASK: Prime Number Checker
//
// Write a C++ program that checks whether a given number is prime.
//
// A prime number is a whole number greater than 1 that has no divisors
// other than 1 and itself (e.g., 2, 3, 5, 7, 11, 13 ...).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLES
// -----------------------------------------------------------------------------
//
//   Enter a number: 7
//   7 is a prime number.
//
//   Enter a number: 10
//   10 is NOT a prime number.
//
//   Enter a number: 1
//   1 is NOT a prime number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement the logic inside a function (see scaffold below).
// - Numbers less than 2 are NOT prime — handle this inside the function.
// - The main() function must call isPrime() and print the result.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================


#include <iostream>
#include <cmath> // Required for sqrt function

// Function to check if a number is prime
bool isPrime(int n) {
    // Numbers less than 2 are not prime
    if (n < 2) {
        return false;
    }
    // 2 is the only even prime number
    if (n == 2) {
        return true;
    }
    // If n is even and greater than 2, it's not prime
    if (n % 2 == 0) {
        return false;
    }
    // Check for divisibility from 3 up to sqrt(n), skipping even numbers
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;

    if (isPrime(num)) {
        std::cout << num << " is a prime number.\n";
    } else {
        std::cout << num << " is NOT a prime number.\n";
    }

    return 0;
}