/**
 * Problem: Palindrome Partitioning II
 * Day: 164 / 288
 * Category: Dynamic Programming
 * Approach: 1D DP min cuts + 2D DP palindromes
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> cuts(n, 0);
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i) {
            int minCuts = i;
            for (int j = 0; j <= i; ++j) {
                if (s[j] == s[i] && (i - j <= 1 || isPal[j + 1][i - 1])) {
                    isPal[j][i] = true;
                    minCuts = (j == 0) ? 0 : min(minCuts, cuts[j - 1] + 1);
                }
            }
            cuts[i] = minCuts;
        }
        return cuts[n - 1];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    int res = s.minCut("aab");

    cout << "Passed test for Palindrome Partitioning II" << endl;
    return 0;
}
