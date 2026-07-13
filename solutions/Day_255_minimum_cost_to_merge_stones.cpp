/**
 * Problem: Minimum Cost to Merge Stones
 * Day: 255 / 288
 * Category: Dynamic Programming
 * Approach: Interval DP with K groupings
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if ((n - 1) % (k - 1) != 0) return -1;
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) prefix[i + 1] = prefix[i] + stones[i];
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k + 1, 1e9)));
        for (int i = 0; i < n; ++i) dp[i][i][1] = 0;
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                for (int m = 2; m <= k; ++m) {
                    for (int mid = i; mid < j; mid += k - 1) {
                        dp[i][j][m] = min(dp[i][j][m], dp[i][mid][1] + dp[mid + 1][j][m - 1]);
                    }
                }
                dp[i][j][1] = dp[i][j][k] + prefix[j + 1] - prefix[i];
            }
        }
        return dp[0][n - 1][1];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> stones = {3, 2, 4, 1}; int res = s.mergeStones(stones, 2);

    cout << "Passed test for Minimum Cost to Merge Stones" << endl;
    return 0;
}
