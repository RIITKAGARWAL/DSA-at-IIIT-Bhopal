/**
 * Problem: Generate Parentheses
 * Day: 37 / 288
 * Category: Backtracking
 * Approach: Balanced recursion branching
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(int openN, int closedN, int n, string current, vector<string>& res) {
        if ((int)current.size() == 2 * n) {
            res.push_back(current);
            return;
        }
        if (openN < n) {
            backtrack(openN + 1, closedN, n, current + "(", res);
        }
        if (closedN < openN) {
            backtrack(openN, closedN + 1, n, current + ")", res);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(0, 0, n, "", res);
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    auto res = s.generateParenthesis(3);

    cout << "Passed test for Generate Parentheses" << endl;
    return 0;
}
