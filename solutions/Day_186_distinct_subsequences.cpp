/**
 * Problem: Distinct Subsequences
 * Day: 186 / 288
 * Category: Dynamic Programming
 * Approach: 2D DP String match
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        vector<vector<unsigned int>> dp(m + 1, vector<unsigned int>(n + 1, 0));
        for (int i = 0; i <= m; ++i) dp[i][0] = 1;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] += dp[i - 1][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    int res = s.numDistinct("rabbbit", "rabbit");

    cout << "Passed test for Distinct Subsequences" << endl;
    return 0;
}
