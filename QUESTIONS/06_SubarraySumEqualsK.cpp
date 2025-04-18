/*Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
 

Constraints:

1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefix_count;
        prefix_count[0] = 1;  // Base case: prefix_sum 0 occurs once
        int prefix_sum = 0, count = 0;

        for (int num : nums) {
            prefix_sum += num;

            // If prefix_sum - k exists, add its count to result
            if (prefix_count.find(prefix_sum - k) != prefix_count.end()) {
                count += prefix_count[prefix_sum - k];
            }

            // Store current prefix_sum frequency
            prefix_count[prefix_sum]++;
        }

        return count;
    }
};

int main() {
    int n, k;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    
    vector<int> nums(n);
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter the target sum (k): ";
    cin >> k;

    Solution solution;
    int result = solution.subarraySum(nums, k);
    cout << "Total number of subarrays with sum " << k << " is: " << result << endl;

    return 0;
}
