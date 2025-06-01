#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Helper function to generate all subsets
    void generateSubsets(vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& result) {
        // Store the current subset
        result.push_back(current);
        
        // Explore further subsets by including remaining elements
        for (int i = index; i < nums.size(); i++) {
            // Include nums[i] in the current subset
            current.push_back(nums[i]);
            // Recur with next index
            generateSubsets(nums, i + 1, current, result);
            // Backtrack: remove the last added element
            current.pop_back();
        }
    }

    // Main function to return all subsets
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;  // To store all subsets
        vector<int> current;         // To store the current subset
        generateSubsets(nums, 0, current, result);  // Start from index 0
        return result;
    }
};

// Example usage
int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3};
    
    vector<vector<int>> allSubsets = solution.subsets(nums);
    
    cout << "All subsets:\n";
    for (const auto& subset : allSubsets) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}\n";
    }

    return 0;
}
