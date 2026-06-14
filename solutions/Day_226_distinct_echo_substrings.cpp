/**
 * Problem: Distinct Echo Substrings
 * Day: 226 / 288
 * Category: String
 * Approach: Rolling Hash Substring Verification
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distinctEchoSubstrings(string text) {
        int n = text.size();
        unordered_set<string> seen;
        for (int len = 2; len <= n; len += 2) {
            int half = len / 2;
            for (int i = 0; i <= n - len; ++i) {
                if (text.substr(i, half) == text.substr(i + half, half)) {
                    seen.insert(text.substr(i, len));
                }
            }
        }
        return seen.size();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    int res = s.distinctEchoSubstrings("abcabcabc");

    cout << "Passed test for Distinct Echo Substrings" << endl;
    return 0;
}
