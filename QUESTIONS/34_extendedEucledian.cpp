#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> gcd(int a, int b) {
        // code here
        // Base case
        if (b == 0) {
            // gcd(a, 0) = a; x = 1, y = 0
            return {a, 1, 0};
        }
        
        // Recursive call 
        vector<int> result = gcd(b, a % b);
        
        int gcd = result[0];
        int x1 = result[1];
        int y1 = result[2];
        
        // Update x and y using results of recursive call
        int x = y1;
        int y = x1 - (a/ b) * y1;
        
        return {gcd, x, y};
    }
};

int main() {
    int a, b;
    cout << "Enter two integers a and b: ";
    cin >> a >> b;

    Solution sol;
    vector<int> result = sol.gcd(a, b);

    cout << "GCD: " << result[0] << "\n";
    cout << "x: " << result[1] << "\n";
    cout << "y: " << result[2] << "\n";

    // Optional: Show the equation
    cout << a << "*" << result[1] << " + " << b << "*" << result[2] << " = " << result[0] << "\n";

    return 0;

}