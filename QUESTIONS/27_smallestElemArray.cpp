#include <iostream>
using namespace std;

int main() {
    int n;

    // Taking the size of the array from the user
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];

    // Taking array elements from the user
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Initializing min with the first element
    int minElement = arr[0];
    
    // Traversing the array to find the minimum element
    for (int i = 1; i < n; i++) {
        if (arr[i] < minElement) {
            minElement = arr[i];
        }
    }

    // Displaying the result
    cout << "The smallest element in the array is: " << minElement << "\n";

    return 0;
}