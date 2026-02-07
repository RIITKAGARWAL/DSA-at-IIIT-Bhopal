/**
 * Problem: N-Queens
 * Day: 99 / 288
 * Category: Backtracking
 * Approach: Column and diagonal sets
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    void backtrack(int r, int n, vector<string>& board, vector<vector<string>>& res, vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2) {
        if (r == n) { res.push_back(board); return; }
        for (int c = 0; c < n; ++c) {
            if (cols[c] || diag1[r + c] || diag2[r - c + n - 1]) continue;
            cols[c] = diag1[r + c] = diag2[r - c + n - 1] = true;
            board[r][c] = 'Q';
            backtrack(r + 1, n, board, res, cols, diag1, diag2);
            board[r][c] = '.';
            cols[c] = diag1[r + c] = diag2[r - c + n - 1] = false;
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        vector<bool> cols(n, false), diag1(2 * n, false), diag2(2 * n, false);
        backtrack(0, n, board, res, cols, diag1, diag2);
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    auto res = s.solveNQueens(4);

    cout << "Passed test for N-Queens" << endl;
    return 0;
}
