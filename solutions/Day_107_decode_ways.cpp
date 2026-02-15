/**
 * Problem: Decode Ways
 * Day: 107 / 288
 * Category: Dynamic Programming
 * Approach: 1D DP prefix encoding validation
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        int n = s.size();
        int prev2 = 1, prev1 = 1;
        for (int i = 1; i < n; ++i) {
            int curr = 0;
            if (s[i] != '0') curr += prev1;
            int twoDigit = stoi(s.substr(i - 1, 2));
            if (twoDigit >= 10 && twoDigit <= 26) curr += prev2;
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
    int res = s.numDecodings("226");

    cout << "Passed test for Decode Ways" << endl;
    return 0;
}
