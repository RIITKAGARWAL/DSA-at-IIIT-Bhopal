/**
 * Problem: Strange Printer
 * Day: 257 / 288
 * Category: Dynamic Programming
 * Approach: Interval DP minimum turn printer
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) dp[i][i] = 1;
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                dp[i][j] = dp[i + 1][j] + 1;
                for (int k = i + 1; k <= j; ++k) {
                    if (s[k] == s[i]) {
                        dp[i][j] = min(dp[i][j], dp[i][k - 1] + (k + 1 <= j ? dp[k + 1][j] : 0));
                    }
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
    int res = s.strangePrinter("aaabbb");

    cout << "Passed test for Strange Printer" << endl;
    return 0;
}
