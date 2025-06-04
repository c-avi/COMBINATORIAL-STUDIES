#include <iostream>
using namespace std;

// Coustom function to find lower bound
int lowerBound(int arr[], int n, int x) {
    int low = 0, high = n;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] < x)
            low = mid + 1;
        else    
            high = mid;
    } 
}

// Custom function to find upper bound
int upperBound(int arr[], int n, int x) {
    int low = 0, high = n;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= x)
            low = mid + 1;
        else    
            high = mid;
    }
    return low;
}

// Custom function to 
int main() {
    int n, k;
    cout << "Enter the number of elements in the sorted array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " sorted elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Enter the value of K: ";
    cin >> k;

    int lb = lowerBound(arr, n, k);
    int ub = upperBound(arr, n, k); 

    // Lower Bound Output
    if (lb == n) {
        cout << "Lower bound doesn't exist\n";
    } else if (arr[lb] == k) {
        cout << "Lower bound of " << k << " is " << arr[lb] << " at index " << lb << "\n";
    } else {
        cout << "Lower bound of " << k << " is " << arr[lb] << " at index " << lb << "\n";
    }

    // Upper Bound Output
    if (ub == n) {
        cout << "Upper bound doesn't exist\n";
    }else {
        cout << "Upper bound of " << k << " is " << arr[ub] << " at index " << ub << "\n";
    }

    return 0;
}