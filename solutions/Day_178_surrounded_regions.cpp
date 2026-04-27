/**
 * Problem: Surrounded Regions
 * Day: 178 / 288
 * Category: Graphs
 * Approach: DFS border flood fill
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != 'O') return;
        board[i][j] = 'T';
        dfs(board, i + 1, j); dfs(board, i - 1, j);
        dfs(board, i, j + 1); dfs(board, i, j - 1);
    }
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) { dfs(board, i, 0); dfs(board, i, n - 1); }
        for (int j = 0; j < n; ++j) { dfs(board, 0, j); dfs(board, m - 1, j); }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == 'T') board[i][j] = 'O';
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<vector<char>> b = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}}; s.solve(b);

    cout << "Passed test for Surrounded Regions" << endl;
    return 0;
}
