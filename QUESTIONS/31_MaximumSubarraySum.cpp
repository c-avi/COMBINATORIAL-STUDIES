#include <iostream>
#include <vector>
#include <algorithm> // for max()

using namespace std;

int main () {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> array(n);
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    int best = array[0], sum = array[0];

    for (int k = 1; k < n; k++) {
        sum = max(array[k], sum + array[k]);
        best = max(best, sum);
    }

    cout << "MAximum Subarray Sum = " << best << "\n";

    return 0;
}