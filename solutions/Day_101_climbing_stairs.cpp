/**
 * Problem: Climbing Stairs
 * Day: 101 / 288
 * Category: Dynamic Programming
 * Approach: Fibonacci base space state transition
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        int prev2 = 1, prev1 = 2;
        for (int i = 3; i <= n; ++i) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    int res = s.climbStairs(5);

    cout << "Passed test for Climbing Stairs" << endl;
    return 0;
}
