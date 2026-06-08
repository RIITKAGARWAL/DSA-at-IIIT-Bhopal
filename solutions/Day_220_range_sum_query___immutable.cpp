/**
 * Problem: Range Sum Query - Immutable
 * Day: 220 / 288
 * Category: Prefix Sum
 * Approach: 1D Prefix sum array
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class NumArray {
    vector<int> prefix;
public:
    NumArray(vector<int>& nums) {
        prefix.assign(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
    }
    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
};
class Solution {
public:
    void test() {
        vector<int> nums = {-2, 0, 3, -5, 2, -1};
        NumArray na(nums);
        na.sumRange(0, 2);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    s.test();

    cout << "Passed test for Range Sum Query - Immutable" << endl;
    return 0;
}
