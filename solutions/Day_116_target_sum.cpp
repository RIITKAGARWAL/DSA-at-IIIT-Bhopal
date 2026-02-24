/**
 * Problem: Target Sum
 * Day: 116 / 288
 * Category: Dynamic Programming
 * Approach: Subset sum reduction
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int n : nums) sum += n;
        if (abs(target) > sum || (sum + target) % 2 != 0) return 0;
        int subsetSum = (sum + target) / 2;
        vector<int> dp(subsetSum + 1, 0);
        dp[0] = 1;
        for (int n : nums) {
            for (int i = subsetSum; i >= n; --i) {
                dp[i] += dp[i - n];
            }
        }
        return dp[subsetSum];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> nums = {1, 1, 1, 1, 1}; int res = s.findTargetSumWays(nums, 3);

    cout << "Passed test for Target Sum" << endl;
    return 0;
}
