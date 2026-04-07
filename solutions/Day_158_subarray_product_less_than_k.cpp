/**
 * Problem: Subarray Product Less Than K
 * Day: 158 / 288
 * Category: Sliding Window
 * Approach: Dynamic window ratio tracking
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int count = 0, prod = 1, l = 0;
        for (int r = 0; r < nums.size(); ++r) {
            prod *= nums[r];
            while (prod >= k) {
                prod /= nums[l++];
            }
            count += (r - l + 1);
        }
        return count;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> nums = {10, 5, 2, 6}; int res = s.numSubarrayProductLessThanK(nums, 100);

    cout << "Passed test for Subarray Product Less Than K" << endl;
    return 0;
}
