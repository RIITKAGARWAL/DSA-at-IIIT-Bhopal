/**
 * Problem: Find All Duplicates in an Array
 * Day: 154 / 288
 * Category: Arrays
 * Approach: In-place sign flipping
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] < 0) res.push_back(idx + 1);
            else nums[idx] = -nums[idx];
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> nums = {4,3,2,7,8,2,3,1}; auto res = s.findDuplicates(nums);

    cout << "Passed test for Find All Duplicates in an Array" << endl;
    return 0;
}
