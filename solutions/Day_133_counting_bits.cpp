/**
 * Problem: Counting Bits
 * Day: 133 / 288
 * Category: Bit Manipulation
 * Approach: DP with right shift
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i >> 1] + (i & 1);
        }
        return dp;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    auto res = s.countBits(5);

    cout << "Passed test for Counting Bits" << endl;
    return 0;
}
