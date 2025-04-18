/*Given an array of distinct elements, find previous greater element for every element. If previous greater element does not exist, print -1.

Examples: 

Input : arr[] = {10, 4, 2, 20, 40, 12, 30}
Output :         -1, 10, 4, -1, -1, 40, 40

Input : arr[] = {10, 20, 30, 40}
Output :        -1, -1, -1, -1

Input : arr[] = {40, 30, 20, 10}
Output :        -1, 40, 30, 20*/

#include <bits/stdc++.h>
using namespace std;

void previousGreaterElement(int arr[], int n) {
    stack<int> st;
    st.push(arr[0]);

    // Previous greater elememnt for first is always -1
    cout << "-1, ";
    
    for (int i = 1; i < n; i++) {
        while (!st.empty() && st.top() < arr[i]){
            st.pop();
        }
        if (st.empty()){
            cout << "-1, ";
        } else {
            cout << st.top() << ", ";
        }
        st.push(arr[i]);
    }

}

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;
    int arr[n];
    cout << "Array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    previousGreaterElement(arr, n);
    return 0;
}
