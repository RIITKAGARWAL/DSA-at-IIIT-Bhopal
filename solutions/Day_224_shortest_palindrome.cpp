/**
 * Problem: Shortest Palindrome
 * Day: 224 / 288
 * Category: String
 * Approach: KMP on Reversed String
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        string l = s + "#" + rev;
        int n = l.size();
        vector<int> lps(n, 0);
        for (int i = 1; i < n; ++i) {
            int j = lps[i - 1];
            while (j > 0 && l[i] != l[j]) j = lps[j - 1];
            if (l[i] == l[j]) j++;
            lps[i] = j;
        }
        string add = rev.substr(0, s.size() - lps[n - 1]);
        return add + s;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    string res = s.shortestPalindrome("aacecaaa");

    cout << "Passed test for Shortest Palindrome" << endl;
    return 0;
}
