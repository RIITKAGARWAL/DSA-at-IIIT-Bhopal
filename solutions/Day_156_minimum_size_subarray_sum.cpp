/**
 * Problem: Minimum Size Subarray Sum
 * Day: 156 / 288
 * Category: Sliding Window
 * Approach: Dynamic window boundary shrinkage
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, sum = 0, minLen = INT_MAX;
        for (int r = 0; r < nums.size(); ++r) {
            sum += nums[r];
            while (sum >= target) {
                minLen = min(minLen, r - l + 1);
                sum -= nums[l++];
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> nums = {2,3,1,2,4,3}; int res = s.minSubArrayLen(7, nums);

    cout << "Passed test for Minimum Size Subarray Sum" << endl;
    return 0;
}
