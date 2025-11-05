/**
 * Problem: Maximum Subarray
 * Day: 5 / 288
 * Category: Arrays
 * Approach: Kadane's Algorithm
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curSum = nums[0], maxSum = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            curSum = max(nums[i], curSum + nums[i]);
            maxSum = max(maxSum, curSum);
        }
        return maxSum;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4}; int res = s.maxSubArray(nums);

    cout << "Passed test for Maximum Subarray" << endl;
    return 0;
}
