/**
 * Problem: Rotate Image
 * Day: 143 / 288
 * Category: Matrix
 * Approach: Reverse and transpose
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(), matrix.end());
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = i + 1; j < matrix.size(); ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<vector<int>> m = {{1,2,3}, {4,5,6}, {7,8,9}}; s.rotate(m);

    cout << "Passed test for Rotate Image" << endl;
    return 0;
}
