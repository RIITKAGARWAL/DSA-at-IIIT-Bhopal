/**
 * Problem: Maximum Size Subarray Sum Equals k
 * Day: 219 / 288
 * Category: Prefix Sum
 * Approach: Prefix sum hash map first occurrence
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> pos;
        int sum = 0, maxLen = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (sum == k) maxLen = max(maxLen, i + 1);
            if (pos.count(sum - k)) {
                maxLen = max(maxLen, i - pos[sum - k]);
            }
            if (!pos.count(sum)) pos[sum] = i;
        }
        return maxLen;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> nums = {1, -1, 5, -2, 3}; int res = s.maxSubArrayLen(nums, 3);

    cout << "Passed test for Maximum Size Subarray Sum Equals k" << endl;
    return 0;
}
