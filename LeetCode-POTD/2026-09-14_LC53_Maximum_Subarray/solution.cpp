#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0], n = nums.size();
        for (int i = 0; i < n; ++i) {
            int cur = 0;
            for (int j = i; j < n; ++j) {
                cur += nums[j];
                max_sum = max(max_sum, cur);
            }
        }
        return max_sum;
    }
};