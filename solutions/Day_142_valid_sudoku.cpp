/**
 * Problem: Valid Sudoku
 * Day: 142 / 288
 * Category: Matrix
 * Approach: 3-way boolean tracking arrays
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9] = {0}, col[9][9] = {0}, block[9][9] = {0};
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    int k = (i / 3) * 3 + j / 3;
                    if (row[i][num] || col[j][num] || block[k][num]) return false;
                    row[i][num] = col[j][num] = block[k][num] = 1;
                }
            }
        }
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<vector<char>> b(9, vector<char>(9, '.')); bool res = s.isValidSudoku(b);

    cout << "Passed test for Valid Sudoku" << endl;
    return 0;
}
