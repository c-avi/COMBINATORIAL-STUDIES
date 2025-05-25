#include <iostream>
#include <vector>
using namespace std;

void fibonacciDP(int n) {
    if (n <= 0) return;

    vector<long long> fib(n + 1);
    fib[0] = 0;
    if (n >= 1) fib[1] = 1;

    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    // Print the Fibonacci series
    for (int i = 0; i <= n; i++) {
        cout << fib[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of terms: ";
    cin >> n;

    cout << "Fibonacci Series up to " << n << " terms:\n";
    fibonacciDP(n);
    
    return 0;
}
