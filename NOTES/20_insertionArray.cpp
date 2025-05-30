#include <iostream>
using namespace std;

int main() {
    int arr[100], n, pos, val;

    // Input size of the array
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    // Input array elements
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Input position and value to insert
    cout << "Enter the position to insert (0 to " << n << "): ";
    cin >> pos;

    // Check if position is valid
    if(pos < 0 || pos > n) {
        cout << "Invalid position!";
        return 0;
    }

    cout << "Enter the value to insert: ";
    cin >> val;

    // Shift elements to the right
    for(int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert value
    arr[pos] = val;
    n++; // Increase the size

    // Output the updated array
    cout << "Array after insertion: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
