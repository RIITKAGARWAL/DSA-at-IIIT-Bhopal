/**
 * Problem: Rotting Oranges
 * Day: 77 / 288
 * Category: Graphs
 * Approach: Multi-source BFS elapsed minute propagation
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), fresh = 0, mins = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) q.push({i, j});
                else if (grid[i][j] == 1) fresh++;
            }
        }
        vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        while (!q.empty() && fresh > 0) {
            int sz = q.size();
            while (sz--) {
                auto [r, c] = q.front(); q.pop();
                for (auto d : dirs) {
                    int nr = r + d.first, nc = c + d.second;
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                        fresh--;
                    }
                }
            }
            mins++;
        }
        return fresh == 0 ? mins : -1;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<vector<int>> grid = {{2,1,1}, {1,1,0}, {0,1,1}}; int res = s.orangesRotting(grid);

    cout << "Passed test for Rotting Oranges" << endl;
    return 0;
}
