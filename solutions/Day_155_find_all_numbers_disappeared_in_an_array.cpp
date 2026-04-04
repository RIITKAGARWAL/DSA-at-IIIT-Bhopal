/**
 * Problem: Find All Numbers Disappeared in an Array
 * Day: 155 / 288
 * Category: Arrays
 * Approach: In-place cyclic mapping
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] > 0) nums[idx] = -nums[idx];
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) res.push_back(i + 1);
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> nums = {4,3,2,7,8,2,3,1}; auto res = s.findDisappearedNumbers(nums);

    cout << "Passed test for Find All Numbers Disappeared in an Array" << endl;
    return 0;
}
