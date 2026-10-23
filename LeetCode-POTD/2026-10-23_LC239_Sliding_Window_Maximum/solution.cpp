#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        for (int i = 0; i <= (int)nums.size() - k; ++i) {
            int maxV = nums[i];
            for (int j = i + 1; j < i + k; ++j) maxV = max(maxV, nums[j]);
            ans.push_back(maxV);
        }
        return ans;
    }
};