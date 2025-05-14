#include <iostream>
using namespace std;

// Recursive function to calculate factorial
long long factorial(int n) {
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main() {
    int num;

    // Taking input from user
    cout << "Enter a positive integer: ";
    cin >> num;

    // Input validation
    if (num < 0) {
        cout << "Factorial is not defined for negative numbers." << "\n";
    } else {
        // Calling recursive function
        long long result = factorial(num);
        cout << "Factorial of " << num << " is: " << result << "\n";
    }

    return 0;
}