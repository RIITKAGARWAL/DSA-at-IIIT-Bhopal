#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    int rob(int idx, const vector<int>& nums) {
        if (idx >= nums.size()) return 0;
        return max(nums[idx] + rob(idx + 2, nums), rob(idx + 1, nums));
    }
public:
    int rob(vector<int>& nums) {
        return rob(0, nums);
    }
};