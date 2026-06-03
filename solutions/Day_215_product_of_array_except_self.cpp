/**
 * Problem: Product of Array Except Self
 * Day: 215 / 288
 * Category: Prefix Sum
 * Approach: Left and right product passes
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        int left = 1;
        for (int i = 0; i < n; ++i) {
            res[i] = left;
            left *= nums[i];
        }
        int right = 1;
        for (int i = n - 1; i >= 0; --i) {
            res[i] *= right;
            right *= nums[i];
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> nums = {1, 2, 3, 4}; auto res = s.productExceptSelf(nums);

    cout << "Passed test for Product of Array Except Self" << endl;
    return 0;
}
