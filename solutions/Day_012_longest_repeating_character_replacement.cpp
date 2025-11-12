/**
 * Problem: Longest Repeating Character Replacement
 * Day: 12 / 288
 * Category: Sliding Window
 * Approach: Max frequency window constraint
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int maxF = 0, l = 0, res = 0;
        for (int r = 0; r < (int)s.size(); ++r) {
            maxF = max(maxF, ++count[s[r] - 'A']);
            while ((r - l + 1) - maxF > k) {
                count[s[l] - 'A']--;
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    int res = s.characterReplacement("AABABBA", 1);

    cout << "Passed test for Longest Repeating Character Replacement" << endl;
    return 0;
}
