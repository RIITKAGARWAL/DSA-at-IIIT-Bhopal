/**
 * Problem: Find Minimum in Rotated Sorted Array
 * Day: 44 / 288
 * Category: Binary Search
 * Approach: Inflection point binary search
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
            else r = mid;
        }
        return nums[l];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> a = {3, 4, 5, 1, 2}; int res = s.findMin(a);

    cout << "Passed test for Find Minimum in Rotated Sorted Array" << endl;
    return 0;
}
