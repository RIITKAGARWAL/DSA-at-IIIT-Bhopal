/**
 * Problem: Product of Array Except Self
 * Day: 4 / 288
 * Category: Arrays
 * Approach: Prefix and suffix product passes
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n, 1);
        int prefix = 1;
        for (int i = 0; i < n; ++i) {
            output[i] = prefix;
            prefix *= nums[i];
        }
        int postfix = 1;
        for (int i = n - 1; i >= 0; --i) {
            output[i] *= postfix;
            postfix *= nums[i];
        }
        return output;
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
