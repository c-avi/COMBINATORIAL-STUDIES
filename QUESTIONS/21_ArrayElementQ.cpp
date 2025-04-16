/*Given an array arr[] of length N and Q queries of 3 types (1, 2, 3) whose operations are as follows:

Type 1: query has input as 1 and the task is to reverse the array.
Type 2: query has input as (2 x) and the task to find the index of x in the result array.
Type 3: query has input as (3 x y) and the task is to swap the elements at index x and y in the array.
The task is to print the result for the query of type 2.

Examples:


Input: N = 5, arr[] = {3, 7, 8, 1, 33}, Q = 4, Queries[][] = {{1}, {2, 8}, {3, 2, 4}, {2, 1}
Output: 2 1
Explanation: Process query wise first is 1 so reverse the list [33, 1, 8, 7, 3], Second query 2 8 so find index of element 8 which is 2, third query is 3 2 4 so swap 2nd and 4th index new array=[33, 1, 3, 7, 8] now the last query is 2 1 so find index of element 1 which is 1 so output 2 1.


Input: N = 6, arr[] = {6, 33, 9, 22, 45, 4}, Q = 5, Queries[][] = {{1}, {3, 0, 4}, {2, 33}, {1}, {2, 9}}
Output: 0 2*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N, Q;
    cin >> N; // Read array size

    vector<int> arr(N);
    for (int i = 0; i < N; i++){
        cin >> arr[i]; // Read array elements
    }

    cin >> Q; // Read number of queries

    while (Q--){
        int type;
        cin >> type; // Read query type

        if (type == 1){
            // Reverse the array
            reverse(arr.begin(), arr.end());
        }
        else if (type == 2){
            int x;
            cin >> x; // element to find
            int index = -1;

            for (int i = 0; i < N; i++){
                if (arr[i] == x){
                    index = i;
                    break;
                }
            }
            cout << index <<" "; // Output result
        }
        else if (type == 3){
            int x, y;
            cin >> x >> y; //Read indices
            swap(arr[x], arr[y]);
        }
    }

    cout << endl; // Ensure proper output format
    return 0;
}

