/**
 * Problem: Find Minimum in Rotated Sorted Array II
 * Day: 159 / 288
 * Category: Binary Search
 * Approach: Boundary trim for duplicates
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[r]) l = mid + 1;
            else if (nums[mid] < nums[r]) r = mid;
            else r--;
        }
        return nums[l];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> nums = {2, 2, 2, 0, 1}; int res = s.findMin(nums);

    cout << "Passed test for Find Minimum in Rotated Sorted Array II" << endl;
    return 0;
}
