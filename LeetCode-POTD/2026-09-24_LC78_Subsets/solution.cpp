#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        for (int mask = 0; mask < (1 << n); ++mask) {
            vector<int> sub;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) sub.push_back(nums[i]);
            }
            res.push_back(sub);
        }
        return res;
    }
};