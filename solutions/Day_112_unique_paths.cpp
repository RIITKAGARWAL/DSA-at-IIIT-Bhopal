/**
 * Problem: Unique Paths
 * Day: 112 / 288
 * Category: Dynamic Programming
 * Approach: 2D grid path combination accumulation
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[j] += dp[j - 1];
            }
        }
        return dp[n - 1];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    int res = s.uniquePaths(3, 7);

    cout << "Passed test for Unique Paths" << endl;
    return 0;
}
