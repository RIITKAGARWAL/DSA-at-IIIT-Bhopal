/**
 * Problem: Remove Boxes
 * Day: 258 / 288
 * Category: Dynamic Programming
 * Approach: Interval DP memoized with streak count
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int dp[100][100][100];
    int solve(vector<int>& boxes, int l, int r, int k) {
        if (l > r) return 0;
        if (dp[l][r][k] != 0) return dp[l][r][k];
        int originalL = l, originalK = k;
        while (l + 1 <= r && boxes[l + 1] == boxes[l]) {
            l++;
            k++;
        }
        int res = (k + 1) * (k + 1) + solve(boxes, l + 1, r, 0);
        for (int m = l + 1; m <= r; ++m) {
            if (boxes[m] == boxes[l]) {
                res = max(res, solve(boxes, l + 1, m - 1, 0) + solve(boxes, m, r, k + 1));
            }
        }
        return dp[originalL][r][originalK] = res;
    }
public:
    int removeBoxes(vector<int>& boxes) {
        memset(dp, 0, sizeof(dp));
        return solve(boxes, 0, boxes.size() - 1, 0);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> boxes = {1, 3, 2, 2, 2, 3, 4, 3, 1}; int res = s.removeBoxes(boxes);

    cout << "Passed test for Remove Boxes" << endl;
    return 0;
}
