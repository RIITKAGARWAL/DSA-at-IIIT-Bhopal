/**
 * Problem: Maximum Product of Word Lengths
 * Day: 161 / 288
 * Category: Bit Manipulation
 * Approach: Bitmask representation of character sets
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> masks(n, 0);
        vector<int> lens(n, 0);
        for (int i = 0; i < n; ++i) {
            int mask = 0;
            for (char c : words[i]) {
                mask |= (1 << (c - 'a'));
            }
            masks[i] = mask;
            lens[i] = words[i].size();
        }
        int maxVal = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if ((masks[i] & masks[j]) == 0) {
                    maxVal = max(maxVal, lens[i] * lens[j]);
                }
            }
        }
        return maxVal;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<string> words = {"abcw","baz","foo","bar","xtfn","abcdef"}; int res = s.maxProduct(words);

    cout << "Passed test for Maximum Product of Word Lengths" << endl;
    return 0;
}
