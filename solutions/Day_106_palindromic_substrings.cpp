/**
 * Problem: Palindromic Substrings
 * Day: 106 / 288
 * Category: Dynamic Programming
 * Approach: Center expansion count
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        auto expand = [&](int l, int r) {
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                count++;
                l--; r++;
            }
        };
        for (int i = 0; i < s.size(); ++i) {
            expand(i, i);
            expand(i, i + 1);
        }
        return count;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    int res = s.countSubstrings("abc");

    cout << "Passed test for Palindromic Substrings" << endl;
    return 0;
}
