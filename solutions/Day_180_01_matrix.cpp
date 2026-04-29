/**
 * Problem: 01 Matrix
 * Day: 180 / 288
 * Category: Graphs
 * Approach: Multi-source BFS
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n, 1e9));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        vector<pair<int, int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            for (auto d : dirs) {
                int nr = r + d.first, nc = c + d.second;
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    if (dist[r][c] + 1 < dist[nr][nc]) {
                        dist[nr][nc] = dist[r][c] + 1;
                        q.push({nr, nc});
                    }
                }
            }
        }
        return dist;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<vector<int>> m = {{0,0,0},{0,1,0},{1,1,1}}; auto res = s.updateMatrix(m);

    cout << "Passed test for 01 Matrix" << endl;
    return 0;
}
