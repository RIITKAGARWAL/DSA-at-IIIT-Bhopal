/**
 * Problem: Combination Sum II
 * Day: 95 / 288
 * Category: Backtracking
 * Approach: Sorted deduplication
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    void backtrack(vector<int>& candidates, int target, int start, vector<int>& path, vector<vector<int>>& res) {
        if (target == 0) { res.push_back(path); return; }
        for (int i = start; i < (int)candidates.size(); ++i) {
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            if (candidates[i] > target) break;
            path.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1, path, res);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
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
    vector<int> cands = {10, 1, 2, 7, 6, 1, 5}; auto res = s.combinationSum2(cands, 8);

    cout << "Passed test for Combination Sum II" << endl;
    return 0;
}
