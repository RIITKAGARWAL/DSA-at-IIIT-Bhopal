/**
 * Problem: Longest Repeating Character Replacement
 * Day: 229 / 288
 * Category: Sliding Window
 * Approach: Max frequency character window check
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int maxFreq = 0, l = 0, maxLen = 0;
        for (int r = 0; r < s.size(); ++r) {
            count[s[r] - 'A']++;
            maxFreq = max(maxFreq, count[s[r] - 'A']);
            if ((r - l + 1) - maxFreq > k) {
                count[s[l] - 'A']--;
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
        }
        return maxLen;
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
