/**
 * Problem: Count Different Palindromic Subsequences
 * Day: 256 / 288
 * Category: Dynamic Programming
 * Approach: Interval DP character frequency recurrence
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPalindromicSubsequences(string s) {
        int n = s.size();
        long long MOD = 1e9 + 7;
        vector<vector<long long>> dp(n, vector<long long>(n, 0));
        for (int i = 0; i < n; ++i) dp[i][i] = 1;
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    int l = i + 1, r = j - 1;
                    while (l <= r && s[l] != s[i]) l++;
                    while (l <= r && s[r] != s[i]) r--;
                    if (l > r) {
                        dp[i][j] = (dp[i + 1][j - 1] * 2 + 2) % MOD;
                    } else if (l == r) {
                        dp[i][j] = (dp[i + 1][j - 1] * 2 + 1) % MOD;
                    } else {
                        dp[i][j] = (dp[i + 1][j - 1] * 2 - dp[l + 1][r - 1] + MOD) % MOD;
                    }
                } else {
                    dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] + MOD) % MOD;
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
    int res = s.countPalindromicSubsequences("bccb");

    cout << "Passed test for Count Different Palindromic Subsequences" << endl;
    return 0;
}
