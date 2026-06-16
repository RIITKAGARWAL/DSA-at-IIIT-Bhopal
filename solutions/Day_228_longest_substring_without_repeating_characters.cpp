/**
 * Problem: Longest Substring Without Repeating Characters
 * Day: 228 / 288
 * Category: Sliding Window
 * Approach: Hash Map character index tracking
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastIdx(128, -1);
        int maxLen = 0, l = 0;
        for (int r = 0; r < s.size(); ++r) {
            if (lastIdx[s[r]] >= l) {
                l = lastIdx[s[r]] + 1;
            }
            lastIdx[s[r]] = r;
            maxLen = max(maxLen, r - l + 1);
        }
        return maxLen;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    int res = s.lengthOfLongestSubstring("abcabcbb");

    cout << "Passed test for Longest Substring Without Repeating Characters" << endl;
    return 0;
}
