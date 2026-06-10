/**
 * Problem: Repeated Substring Pattern
 * Day: 222 / 288
 * Category: String
 * Approach: String concatenation trick
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t = s + s;
        return t.substr(1, t.size() - 2).find(s) != string::npos;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    bool res = s.repeatedSubstringPattern("abab");

    cout << "Passed test for Repeated Substring Pattern" << endl;
    return 0;
}
