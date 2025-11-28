/**
 * Problem: Set Matrix Zeroes
 * Day: 28 / 288
 * Category: Matrix
 * Approach: In-place first row and column markers
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool firstRow = false, firstCol = false;
        for (int i = 0; i < m; ++i) if (matrix[i][0] == 0) firstCol = true;
        for (int j = 0; j < n; ++j) if (matrix[0][j] == 0) firstRow = true;
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (firstCol) for (int i = 0; i < m; ++i) matrix[i][0] = 0;
        if (firstRow) for (int j = 0; j < n; ++j) matrix[0][j] = 0;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}}; s.setZeroes(matrix);

    cout << "Passed test for Set Matrix Zeroes" << endl;
    return 0;
}
