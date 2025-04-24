#include <bits/stdc++.h>
using namespace std;

void subsetSumHelper(vector<int>& arr, int index, int currentSum, vector<int>& result) {
    if (index == arr.size()) {
        result.push_back(currentSum); // Store subset sum
        return;
    }

    // Include the current element
    subsetSumHelper(arr, index + 1, currentSum + arr[index], result);

    // Exclude the current element
    subsetSumHelper(arr, index + 1, currentSum, result);
}
vector<int> subsetSums(vector<int>& arr) {
    // code here
    vector<int> result;
    subsetSumHelper(arr, 0, 0, result);
    sort(result.begin(), result.end()); // Optional sorting for ordered output
    return result;
}
int main() {
    return 0;
}