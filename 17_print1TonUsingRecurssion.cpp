#include <iostream>
using namespace std;

void printNumbers(int n, int current = 1) {
    if (current > n) return;  // Base case: stop when current exceeds n
    cout << current << " ";   // Print current number
    printNumbers(n, current + 1); // Recursive call with next number
}

int main() {
    int n;
    cin >> n;
    printNumbers(n);
    return 0;
}
