/**
 * Problem: Combination Sum
 * Day: 92 / 288
 * Category: Backtracking
 * Approach: Target deduction with element reuse
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    void backtrack(vector<int>& candidates, int target, int start, vector<int>& path, vector<vector<int>>& res) {
        if (target < 0) return;
        if (target == 0) { res.push_back(path); return; }
        for (int i = start; i < (int)candidates.size(); ++i) {
            path.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i, path, res);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        backtrack(candidates, target, 0, path, res);
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> cands = {2, 3, 6, 7}; auto res = s.combinationSum(cands, 7);

    cout << "Passed test for Combination Sum" << endl;
    return 0;
}
