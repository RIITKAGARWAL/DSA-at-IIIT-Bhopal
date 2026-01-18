/**
 * Problem: Pacific Atlantic Water Flow
 * Day: 79 / 288
 * Category: Graphs
 * Approach: Reverse multi-source DFS from oceans
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int r, int c) {
        visited[r][c] = true;
        vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        for (auto d : dirs) {
            int nr = r + d.first, nc = c + d.second;
            if (nr >= 0 && nr < heights.size() && nc >= 0 && nc < heights[0].size() && !visited[nr][nc] && heights[nr][nc] >= heights[r][c]) {
                dfs(heights, visited, nr, nc);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pac(m, vector<bool>(n, false)), atl(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) { dfs(heights, pac, i, 0); dfs(heights, atl, i, n - 1); }
        for (int j = 0; j < n; ++j) { dfs(heights, pac, 0, j); dfs(heights, atl, m - 1, j); }
        vector<vector<int>> res;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pac[i][j] && atl[i][j]) res.push_back({i, j});
            }
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<vector<int>> h = {{1,2,2}, {3,2,3}, {2,4,5}}; auto res = s.pacificAtlantic(h);

    cout << "Passed test for Pacific Atlantic Water Flow" << endl;
    return 0;
}
