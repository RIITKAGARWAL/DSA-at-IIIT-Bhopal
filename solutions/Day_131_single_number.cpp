/**
 * Problem: Single Number
 * Day: 131 / 288
 * Category: Bit Manipulation
 * Approach: XOR cancellation
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int num : nums) {
            res ^= num;
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> nums = {4, 1, 2, 1, 2}; int res = s.singleNumber(nums);

    cout << "Passed test for Single Number" << endl;
    return 0;
}
