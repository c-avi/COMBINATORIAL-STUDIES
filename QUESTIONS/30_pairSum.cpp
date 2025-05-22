#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int left = 0, right = numbers.size() - 1;

    while (left < right) {
        int current_sum = numbers[left] + numbers[right];
        // If current sum = target, return left and right
        if (current_sum == target) {
            return {left + 1, right + 1};
        }
        // if current sum < target , then increase the current sum by moving the left pointer by 1
        else if (current_sum < target) {
            left++;
        } 
        else {
            // If current sum > target, then decrease the current sum by moving right pointer by 1
            right--;
        }
    }
    return {};
}

int main() {
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSum(numbers, target);
    for (int num : result) {
        cout << num << " ";
    } 
    cout << "\n";
    return 0;
}