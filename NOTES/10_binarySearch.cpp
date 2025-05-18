#include <iostream>
#include <vector>
using namespace std;

// Binary Search Function
int binarySearch(const vector<int>& arr, int key) {
    int start = 0;
    int end = arr.size() - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key) 
            return mid; // key found at index mid
        else if (arr[mid] < key)
            start = mid + 1;
        else    
            end = mid - 1;
    }
    return -1; // key not found
}

int main() {
    int n, key;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " sorted elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the element to search: ";
    cin >> key;

    int result = binarySearch(arr, key);

    if (result != -1) 
        cout << "Element found at index " << result << "\n";
    else    
        cout << "Element not found in the array.\n";

    return 0;
}