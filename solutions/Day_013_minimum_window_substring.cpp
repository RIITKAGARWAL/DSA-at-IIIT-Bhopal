/**
 * Problem: Minimum Window Substring
 * Day: 13 / 288
 * Category: Sliding Window
 * Approach: Frequency hash map with formed match counter
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";
        unordered_map<char, int> target, window;
        for (char c : t) target[c]++;
        int have = 0, need = target.size();
        int resLen = INT_MAX, start = 0, l = 0;
        for (int r = 0; r < (int)s.size(); ++r) {
            char c = s[r];
            window[c]++;
            if (target.count(c) && window[c] == target[c]) have++;
            while (have == need) {
                if (r - l + 1 < resLen) {
                    resLen = r - l + 1;
                    start = l;
                }
                window[s[l]]--;
                if (target.count(s[l]) && window[s[l]] < target[s[l]]) have--;
                l++;
            }
        }
        return resLen == INT_MAX ? "" : s.substr(start, resLen);
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
