/**
 * Problem: Implement StrStr / Find the Index of the First Occurrence in a String
 * Day: 221 / 288
 * Category: String
 * Approach: KMP Algorithm LPS Array
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> computeLPS(string& pat) {
        int m = pat.size();
        vector<int> lps(m, 0);
        int len = 0, i = 1;
        while (i < m) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        int n = haystack.size(), m = needle.size();
        vector<int> lps = computeLPS(needle);
        int i = 0, j = 0;
        while (i < n) {
            if (haystack[i] == needle[j]) {
                i++; j++;
            }
            if (j == m) {
                return i - j;
            } else if (i < n && haystack[i] != needle[j]) {
                if (j != 0) j = lps[j - 1];
                else i++;
            }
        }
        return -1;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    int res = s.strStr("sadbutsad", "sad");

    cout << "Passed test for Implement StrStr / Find the Index of the First Occurrence in a String" << endl;
    return 0;
}
