#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void findAndReplace(vector<int>& arr, int n){
    long long s_n = (n * (n + 1)) / 2;
    long long s2_n = (n * (n + 1) * (2 * n + 1)) / 6;

    long long s_actual = 0, s2_actual = 0;
    for (int num : arr){
        s_actual += num;
        s2_actual += (long long)num * num;
    }

    // Calculate x-y and x^2 - y^2
    long long diff1 = s_n - s_actual; // (x-y)
    long long diff2 = s2_n - s2_actual; // (x^2-y^2)

    // Solve for x and y
    long long sum_xy = diff2 / diff1; // (x+y)
    int missing = (diff1 + sum_xy) / 2;
    int duplicate = sum_xy - missing;

    // Replace duplicate with missing
    for (int i = 0; i < n; i++){
        if (arr[i] == duplicate){
            arr[i] = missing;
            break;
        }
    }

    // Sorting to maintain the correct order
    sort(arr.begin(), arr.end());

    // Output
    cout << "Duplicate: " << duplicate << "\n";
    cout << "Missing: " << missing << "\n";
    cout << "Modified Array: ";
    for (int num : arr){
        cout << num << " ";
    }
    cout << endl;
}

int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    findAndReplace(arr, n);
    return 0;
}
