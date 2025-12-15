/**
 * Problem: Search in Rotated Sorted Array
 * Day: 45 / 288
 * Category: Binary Search
 * Approach: Pivot-adjusted binary search
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) return mid;
            if (nums[l] <= nums[mid]) {
                if (target >= nums[l] && target < nums[mid]) r = mid - 1;
                else l = mid + 1;
            } else {
                if (target > nums[mid] && target <= nums[r]) l = mid + 1;
                else r = mid - 1;
            }
        }
        return -1;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> a = {4, 5, 6, 7, 0, 1, 2}; int res = s.search(a, 0);

    cout << "Passed test for Search in Rotated Sorted Array" << endl;
    return 0;
}
