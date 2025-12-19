/**
 * Problem: First and Last Position of Element in Sorted Array
 * Day: 49 / 288
 * Category: Binary Search
 * Approach: Left and right bound binary search
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findBound(vector<int>& nums, int target, bool isFirst) {
        int l = 0, r = nums.size() - 1, ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                ans = mid;
                if (isFirst) r = mid - 1;
                else l = mid + 1;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {findBound(nums, target, true), findBound(nums, target, false)};
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> a = {5, 7, 7, 8, 8, 10}; auto res = s.searchRange(a, 8);

    cout << "Passed test for First and Last Position of Element in Sorted Array" << endl;
    return 0;
}
