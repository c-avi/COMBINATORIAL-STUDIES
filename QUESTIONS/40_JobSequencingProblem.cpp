#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> parent;

    // DSU Find with path compression
    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    // Union operation
    void merge(int u, int v) {
        parent[u] = v;
    }

    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
        vector<pair<int, int>> jobs;

        // Pair jobs as (profit, deadline)
        for (int i = 0; i < n; i++) {
            jobs.push_back({profit[i], deadline[i]});
        }

        // Sort jobs by descending profit
        sort(jobs.rbegin(), jobs.rend());

        // Initialize DSU parent array
        int maxDeadline = *max_element(deadline.begin(), deadline.end());
        parent.resize(maxDeadline + 1);
        for (int i = 0; i <= maxDeadline; i++) {
            parent[i] = i;
        }

        int jobCount = 0, maxProfit = 0;

        for (auto &job : jobs) {
            int p = job.first;
            int d = job.second;

            int availableSlot = find(d);
            if (availableSlot > 0) {
                jobCount++;
                maxProfit += p;
                merge(availableSlot, availableSlot - 1);
            }
        }

        return {jobCount, maxProfit};
    }
};

int main() {
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;

    vector<int> deadline(n), profit(n);

    cout << "Enter deadlines: ";
    for (int i = 0; i < n; i++) {
        cin >> deadline[i];
    }

    cout << "Enter profits: ";
    for (int i = 0; i < n; i++) {
        cin >> profit[i];
    }

    Solution sol;
    vector<int> result = sol.jobSequencing(deadline, profit);

    cout << "Maximum number of jobs: " << result[0] << endl;
    cout << "Maximum profit: " << result[1] << endl;

    return 0;
}
