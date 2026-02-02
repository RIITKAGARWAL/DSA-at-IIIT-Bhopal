/**
 * Problem: Subsets II
 * Day: 94 / 288
 * Category: Backtracking
 * Approach: Duplicate skip branching
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    void backtrack(vector<int>& nums, int start, vector<int>& path, vector<vector<int>>& res) {
        res.push_back(path);
        for (int i = start; i < (int)nums.size(); ++i) {
            if (i > start && nums[i] == nums[i - 1]) continue;
            path.push_back(nums[i]);
            backtrack(nums, i + 1, path, res);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, path, res);
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> nums = {1, 2, 2}; auto res = s.subsetsWithDup(nums);

    cout << "Passed test for Subsets II" << endl;
    return 0;
}
