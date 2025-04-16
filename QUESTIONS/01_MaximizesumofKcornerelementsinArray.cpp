/*Maximize sum of K corner elements in Array
Given an array arr[] and an integer K, the task is to find the maximize the sum of K elements in the Array by taking only corner elements.
Input: arr[] = {8, 4, 4, 8, 12, 3, 2, 9}, K = 3 
Output: 21 
Explanation: 
The optimal strategy is to pick the elements from the array is, two indexes from the beginning and one index from the end. All other possible choice will yield lesser sum. Hence, arr[0] + arr[1] + arr[7] = 21.


Input: arr[] = {2, 1, 14, 6, 4, 3}, K = 3 
Output: 17 
Explanation: 
We will get the maximum sum by picking first three elements from the array. Hence, Optimal choice is: arr[0] + arr[1] + arr[2] = 17 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSumCorners(vector<int>& arr, int K) {
    int n = arr.size();
    int maxSum = 0;

    // Step 1: Take the first K elements from the left as initial sum
    int currSum = 0;
    for (int i = 0; i < K; i++) {
        currSum += arr[i];
    }

    maxSum = currSum;  // Initialize max sum

    // Step 2: Sliding window from right
    int rightSum = 0;
    for (int i = 0; i < K; i++) {
        rightSum += arr[n - 1 - i];   // Add rightmost element
        currSum -= arr[K - 1 - i];    // Remove leftmost element
        maxSum = max(maxSum, currSum + rightSum);
    }

    return maxSum;
}

int main() {
    int n, K;
    
    // Taking user input for array size and K
    cout << "Enter the size of the array: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the value of K: ";
    cin >> K;

    if (K > n) {
        cout << "K cannot be greater than array size!" << endl;
        return 0;
    }

    cout << "Maximum sum of " << K << " corner elements: " << maxSumCorners(arr, K) << endl;

    return 0;
}
