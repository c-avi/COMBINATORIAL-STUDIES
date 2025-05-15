#include <iostream>
#include <vector>
#include <algorithm> // for min_element and max_element
using namespace std;

// Function to compute GCD using Euclidean algorithm
int computeGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
} 

int findGCD(vector<int>& nums) {
    // Find the smallest and largest numbers in the array
    int minNum = *min_element(nums.begin(), nums.end());
    int maxNum = *max_element(nums.begin(), nums.end());

    // Return GCD of minNum and maxNum
    return computeGCD(minNum, maxNum);
}

int main() {
    // Example usage:
    vector<int> nums1 = {2, 5, 6, 9, 10};
    vector<int> nums2 = {7, 5, 6, 8, 3};
    vector<int> nums3 = {3, 3};

    cout << "GCD of example 1: " << findGCD(nums1) << "\n";
    cout << "GCD of example 2: " << findGCD(nums2) << "\n";
    cout << "GCD of example 3: " << findGCD(nums3) << "\n";

    return 0;
}