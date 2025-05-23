#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        // Find the index of the minimum element
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        // Swap the found minimum element with the first element
        if (minIndex != i) 
            swap(arr[i], arr[minIndex]);
    }
}

int main() {
    int n; 
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n]; // or use: int* arr = new int[n];

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) 
        cin >> arr[i];

    selectionSort(arr, n);

    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " ";
    cout << "\n";

    return 0;
}