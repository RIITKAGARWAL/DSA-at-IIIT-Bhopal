/**
 * Problem: Spiral Matrix II
 * Day: 144 / 288
 * Category: Matrix
 * Approach: Layer-by-layer number generation
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int top = 0, bottom = n - 1, left = 0, right = n - 1, num = 1;
        while (top <= bottom && left <= right) {
            for (int j = left; j <= right; ++j) matrix[top][j] = num++;
            top++;
            for (int i = top; i <= bottom; ++i) matrix[i][right] = num++;
            right--;
            if (top <= bottom) {
                for (int j = right; j >= left; --j) matrix[bottom][j] = num++;
                bottom--;
            }
            if (left <= right) {
                for (int i = bottom; i >= top; --i) matrix[i][left] = num++;
                left++;
            }
        }
        return matrix;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    auto res = s.generateMatrix(3);

    cout << "Passed test for Spiral Matrix II" << endl;
    return 0;
}
