#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxIceCreams(int n, vector<int>& prices, int x) {
    sort(prices.begin(), prices.end());

    int count = 0;
    for (int price : prices) {
        if (x >= price) {
            x -= price;
            count++;
        } else{
            break;
        }
    }
    return count;
}

int main() {
    int n, x;
    cin >> n;

    vector<int> prices(n);
    for (int i = 0; i < n; ++i) {
        cin >> prices[i];
    }

    cin >> x;

    cout << maxIceCreams(n, prices, x) << "\n";

    return 0;
}