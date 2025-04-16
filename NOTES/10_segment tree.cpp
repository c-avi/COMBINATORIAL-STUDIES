#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;
const int MOD = 1e9 + 7;

void build(int node, int left, int right, vector <int> &seg, vector <int> &nums)
{
    if (left == right)
    {
        seg[node] = nums[left];
        return;
    }

    int mid = ((left + right) >> 1);

    build(node << 1, left, mid, seg, nums);
    build((node << 1) + 1, mid + 1, right, seg, nums);

    seg[node] = (seg[node << 1] + seg[(node << 1) + 1]);
}

int query(int index, int left, int right, int queryLeft, int queryRight, vector <int> &seg)
{
    if (left > queryRight || right < queryLeft) return 0;

    if (left >= queryLeft and right <= queryRight) return seg[index];

    int mid = ((left + right) >> 1);

    int leftVal = query(index << 1, left, mid, queryLeft, queryRight, seg);
    int rightVal = query((index << 1) + 1, mid + 1, right, queryLeft, queryRight, seg);

    return (leftVal + rightVal);
}

void update(int index, int left, int right, int pos, int val, vector <int> &seg)
{
    if (left == right)
    {
        seg[index] = val;
        return;
    }

    int mid = ((left + right) >> 1);

    if (pos <= mid) update(index << 1, left, mid, pos, val, seg);
    else update((index << 1) + 1, mid + 1, right, pos, val, seg);

    seg[index] = (seg[index << 1] + seg[(index << 1) + 1]);
}

int main()
{
    ios_base :: sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    int n;
    cin >> n;

    vector <int> nums(n), segmentTree(4 * n);

    for (int &num : nums) cin >> num;

    build(1, 0, n-1, segmentTree, nums);

    return 0;
}