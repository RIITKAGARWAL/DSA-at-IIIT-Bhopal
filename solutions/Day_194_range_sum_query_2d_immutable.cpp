/**
 * Problem: Range Sum Query 2D Immutable
 * Day: 194 / 288
 * Category: Dynamic Programming
 * Approach: 2D Prefix Sum Array
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class NumMatrix {
    vector<vector<int>> sum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        sum.assign(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                sum[i][j] = matrix[i - 1][j - 1] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
            }
        }
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum[row2 + 1][col2 + 1] - sum[row1][col2 + 1] - sum[row2 + 1][col1] + sum[row1][col1];
    }
};
class Solution {
public:
    void test() {
        vector<vector<int>> mat = {{3, 0, 1, 4, 2}, {5, 6, 3, 2, 1}, {1, 2, 0, 1, 5}};
        NumMatrix nm(mat); nm.sumRegion(2, 1, 2, 2);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    s.test();

    cout << "Passed test for Range Sum Query 2D Immutable" << endl;
    return 0;
}
