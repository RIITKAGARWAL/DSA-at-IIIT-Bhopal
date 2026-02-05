/**
 * Problem: Palindrome Partitioning
 * Day: 97 / 288
 * Category: Backtracking
 * Approach: Prefix palindrome check
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool isPalindrome(const string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }
    void backtrack(const string& s, int start, vector<string>& path, vector<vector<string>>& res) {
        if (start == s.size()) { res.push_back(path); return; }
        for (int i = start; i < s.size(); ++i) {
            if (isPalindrome(s, start, i)) {
                path.push_back(s.substr(start, i - start + 1));
                backtrack(s, i + 1, path, res);
                path.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        backtrack(s, 0, path, res);
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    auto res = s.partition("aab");

    cout << "Passed test for Palindrome Partitioning" << endl;
    return 0;
}
