#include <bits/stdc++.h>
using namespace std;

// Comparison function to sort items based on value/ weight ratio
bool compare(vector<int>& a, vector<int>& b) {
    double a1 = (1.0 * a[0]) / a[1];
    double b1 = (1.0 * b[0]) / b[1];
    return a1 > b1;
}

double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
    int n = val.size();

    // Create 2D vector to store value and weight
    // items[i][0] = value, items[i][1] = weight

    vector<vector<int>> items(n, vector<int>(2));
}