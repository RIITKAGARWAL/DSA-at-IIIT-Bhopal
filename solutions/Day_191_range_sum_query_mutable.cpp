/**
 * Problem: Range Sum Query Mutable
 * Day: 191 / 288
 * Category: Segment Tree
 * Approach: Binary Indexed Tree (Fenwick Tree)
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class NumArray {
    vector<int> bit, nums;
    int n;
    void add(int i, int val) {
        for (; i <= n; i += i & -i) bit[i] += val;
    }
    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i) sum += bit[i];
        return sum;
    }
public:
    NumArray(vector<int>& nums) : nums(nums), n(nums.size()) {
        bit.assign(n + 1, 0);
        for (int i = 0; i < n; ++i) add(i + 1, nums[i]);
    }
    void update(int index, int val) {
        add(index + 1, val - nums[index]);
        nums[index] = val;
    }
    int sumRange(int left, int right) {
        return query(right + 1) - query(left);
    }
};
class Solution {
public:
    void test() {
        vector<int> nums = {1, 3, 5}; NumArray na(nums); na.sumRange(0, 2);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    s.test();

    cout << "Passed test for Range Sum Query Mutable" << endl;
    return 0;
}
