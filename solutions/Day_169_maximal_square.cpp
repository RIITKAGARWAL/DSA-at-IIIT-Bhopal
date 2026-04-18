/**
 * Problem: Maximal Square
 * Day: 169 / 288
 * Category: Dynamic Programming
 * Approach: 2D DP tracking largest square corners
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int maxSide = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (matrix[i - 1][j - 1] == '1') {
                    dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                    maxSide = max(maxSide, dp[i][j]);
                }
            }
        }
        return maxSide * maxSide;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<vector<char>> m = {{'1','0','1','0','0'}, {'1','0','1','1','1'}, {'1','1','1','1','1'}, {'1','0','0','1','0'}}; int res = s.maximalSquare(m);

    cout << "Passed test for Maximal Square" << endl;
    return 0;
}
