#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Function to find signed distance to nearest vendor
int signedDistanceToNearestVendor(const vector<int>& vendors, int customer) {
    // if the number is at the same position as a vendor
    if (binary_search(vendors.begin(), vendors.end(), customer)) {
        return 0;
    }

    int left = 0, right = vendors.size() - 1;
    int nearest = vendors[0];
    int minDist = abs(customer - vendors[0]);

    // Binary search to find closest vendor
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int vendor = vendors[mid];
        int dist = abs(vendor - customer);

        if (dist < minDist || (dist == minDist && vendor < nearest)) {
            nearest = vendor;
            minDist = dist;
        } 

        if (vendor < customer) 
            left = mid + 1;
        else    
            right = mid - 1;
    }

    return nearest - customer;

}



int main() {
    int numVendors, numCustomers;
    cout << "Enter number of vendors: ";
    cin >> numVendors;
    vector<int> vendors(numVendors);

    cout << "Enter vendor positions: ";
    for (int i = 0; i < numVendors; ++i) {
        cin >> vendors[i];
    }

    cout << "Enter number of customers: ";
    cin >> numCustomers;
    vector<int> customers(numCustomers);
    cout << "Enter customer positions: ";
    for (int i = 0; i < numCustomers; ++i) {
        cin >> customers[i];
    }

    sort(vendors.begin(), vendors.end());

    cout << "Signed distances to nearest vendors:\n";
    for (int customer : customers) {
        int signedDist = signedDistanceToNearestVendor(vendors, customer);
        cout << signedDist << " ";
    }
    cout << "\n";

    return 0;
}