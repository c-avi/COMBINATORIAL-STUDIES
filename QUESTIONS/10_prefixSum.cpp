#include <iostream>
using namespace std;

int prefixSumBetweenLR(int arr[], int l, int r){

}

int main(){
    int n, l ,r;
    cout << "Enter no of elements in an array: ";
    cin >> n;
    int arr[n];
    cout << "Enter array elements: ";
    for (int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    cout << "Enter l and r value: ";
    cin >> l >> r;
    prefixSumBetweenLR(arr, l, r);
    // eg1 : int arr[] = {1, 2, 3, 4, 5, 6};
    // int l = 2 , r = 4;
    // o se 4 tk ka sum lunga and - 0 se 2-1 tk ka sum



    return 0;
}