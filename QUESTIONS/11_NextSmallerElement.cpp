/*Given an array, print the Next Smaller Element (NSE) for every element. The NSE for an element x is the first smaller element on the right side of x in the array. For elements for which no smaller element exists (on the right side), then consider NSE as -1. 

Examples:

Input: [4, 8, 5, 2, 25]
Output: [2, 5, 2, -1, -1]*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> nextSmallerElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() >= arr[i]) {
            st.pop();  // Pop elements that are greater or equal
        }

        result[i] = st.empty() ? -1 : st.top();  // Set NSE
        st.push(arr[i]);  // Push current element onto the stack
    }

    return result;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> result = nextSmallerElement(arr);

    cout << "Next Smaller Elements: ";
    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}
