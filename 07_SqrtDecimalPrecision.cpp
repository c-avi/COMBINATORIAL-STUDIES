/*Sqrt(x)
Given a positive number n and precision p, find the square root of number upto p decimal places using binary search.
Input : number = 50, precision = 3
Output : 7.071

Input : number = 10, precision = 4
Output : 3.1622*/

#include <iostream>
using namespace std;

// Function to find square root using binary search
double squareRoot(int number, int precision) {
    int start = 0, end = number;
    double ans = 0.0;

    // Binary search for integer part
    while (start <= end) {
        long long mid = start + (end - start) / 2;
        long long sq = mid * mid;

        if (sq == number) {
            return mid;
        } else if (sq < number) {
            ans = mid;  // Store the last valid integer answer
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    // Linear search for decimal part
    double increment = 0.1;
    for (int i = 0; i < precision; i++) {
        while (ans * ans <= number) {
            ans += increment;
        }
        ans -= increment;  // Step back to the correct value
        increment /= 10;   // Reduce precision step
    }

    return ans;
}

int main() {
    int number, precision;
    cout << "Enter the number: ";
    cin >> number;
    cout << "Enter precision: ";
    cin >> precision;

    double result = squareRoot(number, precision);
    cout << "Square root: " << fixed << result << endl;

    return 0;
}
