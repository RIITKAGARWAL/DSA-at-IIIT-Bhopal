#include <vector>
using namespace std;
class Solution {
    bool canReach(int idx, const vector<int>& nums) {
        if (idx == nums.size() - 1) return true;
        int maxJ = min((int)nums.size() - 1, idx + nums[idx]);
        for (int next = idx + 1; next <= maxJ; ++next) {
            if (canReach(next, nums)) return true;
        }
        return false;
    }
public:
    bool canJump(vector<int>& nums) {
        return canReach(0, nums);
    }
};