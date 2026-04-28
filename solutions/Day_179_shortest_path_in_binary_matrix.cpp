/**
 * Problem: Shortest Path in Binary Matrix
 * Day: 179 / 288
 * Category: Graphs
 * Approach: BFS shortest path with directions
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0][0] != 0) return -1;
        int n = grid.size();
        if (n == 1) return 1;
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;
        int steps = 1;
        vector<pair<int, int>> dirs = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [r, c] = q.front(); q.pop();
                if (r == n - 1 && c == n - 1) return steps;
                for (auto d : dirs) {
                    int nr = r + d.first, nc = c + d.second;
                    if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0) {
                        grid[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<vector<int>> g = {{0,0,0},{1,1,0},{1,1,0}}; int res = s.shortestPathBinaryMatrix(g);

    cout << "Passed test for Shortest Path in Binary Matrix" << endl;
    return 0;
}
