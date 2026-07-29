// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )    e.g.  10 + 3  =  13
//   2. Subtraction       ( - )    e.g.  10 - 3  =  7
//   3. Multiplication    ( * )    e.g.  10 * 3  =  30
//   4. Division          ( / )    e.g.  10 / 3  =  3.33
//   5. Modulus           ( % )    e.g.  10 % 3  =  1  (remainder)
//   6. Exponentiation    ( ^ )    e.g.  2 ^ 8   =  256
//   7. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        SIMPLE CALCULATOR
//   ============================
//   1. Addition
//   2. Subtraction
//   3. Multiplication
//   4. Division
//   5. Modulus
//   6. Exponentiation
//   7. Quit
//   Select an operation (1-7):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Select an operation (1-7): 4
//   Enter first number : 10
//   Enter second number: 3
//   Result: 10 / 3 = 3.33
//
//   Select an operation (1-7): 4
//   Enter first number : 5
//   Enter second number: 0
//   Error: Cannot divide by zero.
//
//   Select an operation (1-7): 7
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Each arithmetic operation MUST be written as its own function.
// - Use a loop so the calculator keeps running until the user selects Quit.
// - Division by zero must be caught and handled with a clear error message
//   (do NOT let the program crash).
// - Use fixed and setprecision(2) to display results to 2 decimal places.
// - Handle invalid menu choices gracefully.
// - For exponentiation use a loop or the pow() function from <cmath>.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

// Returns true on success, false if b is zero (division by zero)
bool divide(double a, double b, double& result) {
    if (b == 0) {
        return false;
    }
    result = a / b;
    return true;
}

// Returns true on success, false if b is zero (modulus by zero)
bool modulus(int a, int b, int& result) {
    if (b == 0) {
        return false;
    }
    result = a % b;
    return true;
}

double exponentiate(double base, double exponent) {
    return pow(base, exponent);
}

void showMenu() {
    cout << "\n============================\n";
    cout << "     SIMPLE CALCULATOR\n";
    cout << "============================\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";
    cout << "5. Modulus\n";
    cout << "6. Exponentiation\n";
    cout << "7. Quit\n";
    cout << "Select an operation (1-7): ";
}

int main() {
    int choice;
    bool running = true;

    cout << fixed << setprecision(2);

    while (running) {
        showMenu();
        cin >> choice;

        if (choice == 7) {
            cout << "Goodbye!\n";
            running = false;
            continue;
        }

        if (choice < 1 || choice > 7) {
            cout << "Error: Invalid choice. Please enter 1-7.\n";
            continue;
        }

        double a, b;
        cout << "Enter first number : ";
        cin >> a;
        cout << "Enter second number: ";
        cin >> b;

        switch (choice) {
            case 1:
                cout << "Result: " << a << " + " << b << " = " << add(a, b) << "\n";
                break;
            case 2:
                cout << "Result: " << a << " - " << b << " = " << subtract(a, b) << "\n";
                break;
            case 3:
                cout << "Result: " << a << " * " << b << " = " << multiply(a, b) << "\n";
                break;
            case 4: {
                double result;
                if (divide(a, b, result)) {
                    cout << "Result: " << a << " / " << b << " = " << result << "\n";
                } else {
                    cout << "Error: Cannot divide by zero.\n";
                }
                break;
            }
            case 5: {
                int result;
                if (modulus(static_cast<int>(a), static_cast<int>(b), result)) {
                    cout << "Result: " << static_cast<int>(a) << " % " << static_cast<int>(b) << " = " << result << "\n";
                } else {
                    cout << "Error: Cannot perform modulus by zero.\n";
                }
                break;
            }
            case 6:
                cout << "Result: " << a << " ^ " << b << " = " << exponentiate(a, b) << "\n";
                break;
        }
    }

    return 0;
}