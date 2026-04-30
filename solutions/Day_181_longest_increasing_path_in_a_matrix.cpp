/**
 * Problem: Longest Increasing Path in a Matrix
 * Day: 181 / 288
 * Category: Graphs
 * Approach: DFS with Memoization
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    int dfs(vector<vector<int>>& matrix, int r, int c, vector<vector<int>>& memo) {
        if (memo[r][c] != 0) return memo[r][c];
        int maxPath = 1;
        for (auto& d : dirs) {
            int nr = r + d[0], nc = c + d[1];
            if (nr >= 0 && nr < matrix.size() && nc >= 0 && nc < matrix[0].size() && matrix[nr][nc] > matrix[r][c]) {
                maxPath = max(maxPath, 1 + dfs(matrix, nr, nc, memo));
            }
        }
        return memo[r][c] = maxPath;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size(), maxLen = 0;
        vector<vector<int>> memo(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                maxLen = max(maxLen, dfs(matrix, i, j, memo));
            }
        }
        return maxLen;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<vector<int>> m = {{9,9,4},{6,6,8},{2,1,1}}; int res = s.longestIncreasingPath(m);

    cout << "Passed test for Longest Increasing Path in a Matrix" << endl;
    return 0;
}
