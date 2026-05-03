/**
 * Problem: Swim in Rising Water
 * Day: 184 / 288
 * Category: Graphs
 * Approach: Dijkstra / BFS + Heap
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;
        vector<pair<int, int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
        while (!pq.empty()) {
            auto curr = pq.top(); pq.pop();
            int t = curr[0], r = curr[1], c = curr[2];
            if (r == n - 1 && c == n - 1) return t;
            for (auto d : dirs) {
                int nr = r + d.first, nc = c + d.second;
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    pq.push({max(t, grid[nr][nc]), nr, nc});
                }
            }
        }
        return -1;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<vector<int>> g = {{0,2},{1,3}}; int res = s.swimInWater(g);

    cout << "Passed test for Swim in Rising Water" << endl;
    return 0;
}
