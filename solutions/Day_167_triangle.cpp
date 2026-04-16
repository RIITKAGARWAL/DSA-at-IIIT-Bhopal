/**
 * Problem: Triangle
 * Day: 167 / 288
 * Category: Dynamic Programming
 * Approach: Bottom-up 1D DP optimization
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp = triangle.back();
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
            }
        }
        return dp[0];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<vector<int>> t = {{2}, {3,4}, {6,5,7}, {4,1,8,3}}; int res = s.minimumTotal(t);

    cout << "Passed test for Triangle" << endl;
    return 0;
}
