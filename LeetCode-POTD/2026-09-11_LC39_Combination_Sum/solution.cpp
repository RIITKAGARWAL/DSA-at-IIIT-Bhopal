#include <vector>
using namespace std;
class Solution {
    void backtrack(vector<int>& c, int target, int start, vector<int>& path, vector<vector<int>>& res) {
        if (target == 0) { res.push_back(path); return; }
        if (target < 0) return;
        for (int i = start; i < c.size(); ++i) {
            path.push_back(c[i]);
            backtrack(c, target - c[i], i, path, res);
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