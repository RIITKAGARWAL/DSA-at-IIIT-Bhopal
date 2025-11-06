/**
 * Problem: Maximum Product Subarray
 * Day: 6 / 288
 * Category: Arrays
 * Approach: Dynamic min/max tracking
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0], curMin = 1, curMax = 1;
        for (int n : nums) {
            int temp = curMax * n;
            curMax = max({n, curMax * n, curMin * n});
            curMin = min({n, temp, curMin * n});
            res = max(res, curMax);
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> nums = {2, 3, -2, 4}; int res = s.maxProduct(nums);

    cout << "Passed test for Maximum Product Subarray" << endl;
    return 0;
}
