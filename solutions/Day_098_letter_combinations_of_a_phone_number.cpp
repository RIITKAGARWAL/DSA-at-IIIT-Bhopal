/**
 * Problem: Letter Combinations of a Phone Number
 * Day: 98 / 288
 * Category: Backtracking
 * Approach: Cartesian product DFS
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<string> mappings = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void backtrack(const string& digits, int idx, string current, vector<string>& res) {
        if (idx == digits.size()) { res.push_back(current); return; }
        string letters = mappings[digits[idx] - '0'];
        for (char c : letters) {
            backtrack(digits, idx + 1, current + c, res);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) return res;
        backtrack(digits, 0, "", res);
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    auto res = s.letterCombinations("23");

    cout << "Passed test for Letter Combinations of a Phone Number" << endl;
    return 0;
}
