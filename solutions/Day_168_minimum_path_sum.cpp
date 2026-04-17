/**
 * Problem: Minimum Path Sum
 * Day: 168 / 288
 * Category: Dynamic Programming
 * Approach: In-place grid DP accumulation
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue;
                if (i == 0) grid[i][j] += grid[i][j - 1];
                else if (j == 0) grid[i][j] += grid[i - 1][j];
                else grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid[m - 1][n - 1];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<vector<int>> grid = {{1,3,1}, {1,5,1}, {4,2,1}}; int res = s.minPathSum(grid);

    cout << "Passed test for Minimum Path Sum" << endl;
    return 0;
}
