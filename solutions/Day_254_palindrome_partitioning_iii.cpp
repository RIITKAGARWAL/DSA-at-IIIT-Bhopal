/**
 * Problem: Palindrome Partitioning III
 * Day: 254 / 288
 * Category: Dynamic Programming
 * Approach: 2D DP cost matrix with K partitions
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int palindromePartition(string s, int k) {
        int n = s.size();
        vector<vector<int>> cost(n, vector<int>(n, 0));
        for (int len = 2; len <= n; ++len) {
            for (int i = 0, j = len - 1; j < n; ++i, ++j) {
                cost[i][j] = (s[i] != s[j]) + cost[i + 1][j - 1];
            }
        }
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 1e9));
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= min(i, k); ++j) {
                if (j == 1) {
                    dp[i][1] = cost[0][i - 1];
                } else {
                    for (int p = j - 1; p < i; ++p) {
                        dp[i][j] = min(dp[i][j], dp[p][j - 1] + cost[p][i - 1]);
                    }
                }
            }
        }
        return dp[n][k];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    int res = s.palindromePartition("abc", 2);

    cout << "Passed test for Palindrome Partitioning III" << endl;
    return 0;
}
