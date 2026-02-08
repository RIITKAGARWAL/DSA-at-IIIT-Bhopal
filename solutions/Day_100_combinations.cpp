/**
 * Problem: Combinations
 * Day: 100 / 288
 * Category: Backtracking
 * Approach: Choose k elements from n
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    void backtrack(int n, int k, int start, vector<int>& path, vector<vector<int>>& res) {
        if (path.size() == k) { res.push_back(path); return; }
        for (int i = start; i <= n; ++i) {
            path.push_back(i);
            backtrack(n, k, i + 1, path, res);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> path;
        backtrack(n, k, 1, path, res);
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    auto res = s.combine(4, 2);

    cout << "Passed test for Combinations" << endl;
    return 0;
}
