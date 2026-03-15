/**
 * Problem: Missing Number
 * Day: 135 / 288
 * Category: Bit Manipulation
 * Approach: XOR index and values
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = nums.size();
        for (int i = 0; i < (int)nums.size(); ++i) {
            res ^= i ^ nums[i];
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> nums = {3, 0, 1}; int res = s.missingNumber(nums);

    cout << "Passed test for Missing Number" << endl;
    return 0;
}
