/**
 * Problem: Longest Substring Without Repeating Characters
 * Day: 11 / 288
 * Category: Sliding Window
 * Approach: Dynamic window with index hash map
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> seen;
        int maxLen = 0, start = 0;
        for (int end = 0; end < (int)s.size(); ++end) {
            if (seen.find(s[end]) != seen.end()) {
                start = max(start, seen[s[end]] + 1);
            }
            seen[s[end]] = end;
            maxLen = max(maxLen, end - start + 1);
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
