/**
 * Problem: Number of Islands
 * Day: 74 / 288
 * Category: Graphs
 * Approach: Grid DFS flood fill
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= (int)grid.size() || j < 0 || j >= (int)grid[0].size() || grid[i][j] == '0') return;
        grid[i][j] = '0';
        dfs(grid, i + 1, j); dfs(grid, i - 1, j);
        dfs(grid, i, j + 1); dfs(grid, i, j - 1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int i = 0; i < (int)grid.size(); ++i) {
            for (int j = 0; j < (int)grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<vector<char>> grid = {{'1','1','0'}, {'0','1','0'}, {'0','0','1'}}; int res = s.numIslands(grid);

    cout << "Passed test for Number of Islands" << endl;
    return 0;
}
