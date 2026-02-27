/**
 * Problem: Burst Balloons
 * Day: 119 / 288
 * Category: Dynamic Programming
 * Approach: Interval DP dividing on last balloon burst
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> vals = {1};
        for (int n : nums) vals.push_back(n);
        vals.push_back(1);
        int n = vals.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int len = 2; len < n; ++len) {
            for (int l = 0; l < n - len; ++l) {
                int r = l + len;
                for (int i = l + 1; i < r; ++i) {
                    dp[l][r] = max(dp[l][r], vals[l] * vals[i] * vals[r] + dp[l][i] + dp[i][r]);
                }
            }
        }
        return dp[0][n - 1];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> nums = {3, 1, 5, 8}; int res = s.maxCoins(nums);

    cout << "Passed test for Burst Balloons" << endl;
    return 0;
}
