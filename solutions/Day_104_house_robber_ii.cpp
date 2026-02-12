/**
 * Problem: House Robber II
 * Day: 104 / 288
 * Category: Dynamic Programming
 * Approach: Circular array split into two linear passes
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int robLinear(vector<int>& nums, int start, int end) {
        int rob1 = 0, rob2 = 0;
        for (int i = start; i <= end; ++i) {
            int temp = max(nums[i] + rob1, rob2);
            rob1 = rob2;
            rob2 = temp;
        }
        return rob2;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        return max(robLinear(nums, 0, n - 2), robLinear(nums, 1, n - 1));
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> nums = {2, 3, 2}; int res = s.rob(nums);

    cout << "Passed test for House Robber II" << endl;
    return 0;
}
