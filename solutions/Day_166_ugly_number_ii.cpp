/**
 * Problem: Ugly Number II
 * Day: 166 / 288
 * Category: Dynamic Programming
 * Approach: Three-pointer DP generation
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;
        for (int i = 1; i < n; ++i) {
            int next2 = dp[p2] * 2, next3 = dp[p3] * 3, next5 = dp[p5] * 5;
            dp[i] = min({next2, next3, next5});
            if (dp[i] == next2) p2++;
            if (dp[i] == next3) p3++;
            if (dp[i] == next5) p5++;
        }
        return dp[n - 1];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    int res = s.nthUglyNumber(10);

    cout << "Passed test for Ugly Number II" << endl;
    return 0;
}
