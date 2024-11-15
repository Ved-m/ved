#include <iostream>
using namespace std;

// Function to print Fibonacci series without recursion
void fibonacciWithoutRecursion(int n) {
    int a = 0, b = 1, nextTerm;
    cout << "Fibonacci series (Without Recursion): ";
    for (int i = 1; i <= n; i++) {
        cout << a << " ";
        nextTerm = a + b;
        a = b;
        b = nextTerm;
    }
    cout << endl;
}

// Function to calculate the nth Fibonacci number using recursion
int fibonacciRecursive(int n) {
    if (n <= 1)
        return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

// Function to print Fibonacci series with recursion
void fibonacciWithRecursion(int n) {
    cout << "Fibonacci series (With Recursion): ";
    for (int i = 0; i < n; i++) {
        cout << fibonacciRecursive(i) << " ";
    }
    cout << endl;
}

// Main menu-driven program
int main() {
    int choice, n;

    do {
        cout << "\nMenu:\n";
        cout << "1. Print Fibonacci series without recursion\n";
        cout << "2. Print Fibonacci series with recursion\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1 || choice == 2) {
            cout << "Enter the number of terms: ";
            cin >> n;
        }

        switch (choice) {
            case 1:
                fibonacciWithoutRecursion(n);
                break;
            case 2:
                fibonacciWithRecursion(n);
                break;
            case 3:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    } while (choice != 3);

    return 0;
}

