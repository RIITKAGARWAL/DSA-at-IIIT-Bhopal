/**
 * Problem: Minimum Window Substring
 * Day: 227 / 288
 * Category: Sliding Window
 * Approach: Frequency character matching window
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";
        vector<int> target(128, 0);
        for (char c : t) target[c]++;
        int required = t.size(), formed = 0;
        int l = 0, r = 0, minLen = INT_MAX, head = 0;
        while (r < s.size()) {
            char c = s[r];
            if (target[c] > 0) {
                target[c]--;
                if (target[c] >= 0) formed++;
            }
            r++;
            while (formed == required) {
                if (r - l < minLen) {
                    minLen = r - l;
                    head = l;
                }
                char leftChar = s[l];
                target[leftChar]++;
                if (target[leftChar] > 0) formed--;
                l++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(head, minLen);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    string res = s.minWindow("ADOBECODEBANC", "ABC");

    cout << "Passed test for Minimum Window Substring" << endl;
    return 0;
}
