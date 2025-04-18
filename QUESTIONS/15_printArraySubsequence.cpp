#include <iostream>
#include <vector>
using namespace std;

void generateSubsequences(vector<int>& arr, vector<int>& output, int index) {
    // no of subsequence = 2^n - 1
    if (index == arr.size()) { // Base case: if we reach the end of the array
        cout << "{";
        for (int i = 0; i < output.size(); i++) {
            cout << output[i];
            if (i < output.size() - 1) cout << ", ";
        }
        cout << "}" << endl; // Print the subsequence (including empty one)
        return;
    }

    // Exclude the current element and move to the next
    generateSubsequences(arr, output, index + 1);

    // Include the current element and move to the next
    output.push_back(arr[index]);
    generateSubsequences(arr, output, index + 1);
    
    // Backtrack to remove the current element for other recursive calls
    output.pop_back();
}

int main() {
    int n;
    cin >> n; // Input array size
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i]; // Input array elements
    
    vector<int> output;
    generateSubsequences(arr, output, 0); // Call function with empty output initially
    
    return 0;
}
