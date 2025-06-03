#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class Solution {
public:
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void insertionSort(vector<int>& nums, int left, int right) {
        for (int i = left + 1; i <= right; i++) {
            int key = nums[i];
            int j = i - 1;
            while (j >= left && nums[j] > key) {
                nums[j + 1] = nums[j];
                j--;
            }
            nums[j + 1] = key;
        }
    }

    int partition(vector<int>& nums, int left, int right) {
        int pivotIndex = left + rand() % (right - left + 1);
        int pivot = nums[pivotIndex];
        swap(nums[pivotIndex], nums[right]);
        int i = left - 1;

        for (int j = left; j < right; j++) {
            if (nums[j] < pivot) {
                i++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[right]);
        return i + 1;
    }

    void quicksort(vector<int>& nums, int left, int right) {
        if (left < right) {
            if (right - left <= 10) {
                insertionSort(nums, left, right);
            } else {
                int pivotIndex = partition(nums, left, right);
                quicksort(nums, left, pivotIndex - 1);
                quicksort(nums, pivotIndex + 1, right);
            }
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        srand(time(0));
        quicksort(nums, 0, nums.size() - 1);
        return nums;
    }
};

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    Solution sol;
    vector<int> sorted = sol.sortArray(nums);

    cout << "Sorted array:\n";
    for (int num : sorted) {
        cout << num << " ";
    }
    cout << "\n";

    return 0;
}
