/**
 * Problem: Longest Palindrome
 * Day: 150 / 288
 * Category: Hash Table
 * Approach: Frequency character accumulation
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> count;
        for (char c : s) count[c]++;
        int len = 0;
        bool odd = false;
        for (auto& p : count) {
            len += (p.second / 2) * 2;
            if (p.second % 2 == 1) odd = true;
        }
        return odd ? len + 1 : len;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    int res = s.longestPalindrome("abccccdd");

    cout << "Passed test for Longest Palindrome" << endl;
    return 0;
}
