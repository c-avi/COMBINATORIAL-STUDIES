#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

// Function to check if a number is an Armstrong number
bool isArmstrong(int num) {
    int original = num;
    int sum = 0, digits = 0;

    int temp = num;
    while (temp > 0) {
        digits++;
        temp /= 10;
    }

    temp = num;
    while (temp > 0) {
        int digit = temp % 10;
        sum += static_cast<int>(round(pow(digit, digits))); // use the round to avoid float errors
        temp /= 10;
    }

    return sum == original;
}

// Function that returns a vector<string> with results
vector<string> getArmstrongResults(const vector<int>& numbers) {
    vector<string> results;

    for (int num : numbers) {
        if (isArmstrong(num)) {
            results.push_back("Armstrong");
        } else {
            results.push_back("Not Armstrong");
        }
    }

    return results;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> numbers(n);
    cout << "Enter " << n << " numbers:\n";
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    vector<string> output = getArmstrongResults(numbers);

    // Display the result
    cout << "\nResults as vector<string>:\n";
    for (const string& result : output) {
        cout << result << " ";
    }
    cout << endl;

    return 0;
}
