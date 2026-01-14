/**
 * Problem: Max Area of Island
 * Day: 75 / 288
 * Category: Graphs
 * Approach: Area accumulation grid DFS
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= (int)grid.size() || j < 0 || j >= (int)grid[0].size() || grid[i][j] == 0) return 0;
        grid[i][j] = 0;
        return 1 + dfs(grid, i + 1, j) + dfs(grid, i - 1, j) + dfs(grid, i, j + 1) + dfs(grid, i, j - 1);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for (int i = 0; i < (int)grid.size(); ++i) {
            for (int j = 0; j < (int)grid[0].size(); ++j) {
                if (grid[i][j] == 1) maxArea = max(maxArea, dfs(grid, i, j));
            }
        }
        return maxArea;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<vector<int>> grid = {{1,1,0}, {0,1,0}}; int res = s.maxAreaOfIsland(grid);

    cout << "Passed test for Max Area of Island" << endl;
    return 0;
}
