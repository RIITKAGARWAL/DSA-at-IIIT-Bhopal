#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        vector<int> curr = intervals[0];
        for (size_t i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] <= curr[1]) {
                curr[1] = max(curr[1], intervals[i][1]);
            } else {
                res.push_back(curr);
                curr = intervals[i];
            }
        }
        res.push_back(curr);
        return res;
    }
};