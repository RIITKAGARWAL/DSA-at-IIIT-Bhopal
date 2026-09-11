#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    void dfs(const vector<int>& c, int target, int idx, vector<int>& curr, vector<vector<int>>& ans) {
        if (target == 0) { ans.push_back(curr); return; }
        for (int i = idx; i < c.size(); ++i) {
            if (c[i] > target) break;
            curr.push_back(c[i]);
            dfs(c, target - c[i], i, curr, ans);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        dfs(candidates, target, 0, curr, ans);
        return ans;
    }
};