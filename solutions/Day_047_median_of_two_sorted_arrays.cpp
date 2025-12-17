/**
 * Problem: Median of Two Sorted Arrays
 * Day: 47 / 288
 * Category: Binary Search
 * Approach: Binary search on partition cuts
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        int m = nums1.size(), n = nums2.size();
        int l = 0, r = m;
        while (l <= r) {
            int cut1 = l + (r - l) / 2;
            int cut2 = (m + n + 1) / 2 - cut1;
            
            int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int r1 = (cut1 == m) ? INT_MAX : nums1[cut1];
            int r2 = (cut2 == n) ? INT_MAX : nums2[cut2];
            
            if (l1 <= r2 && l2 <= r1) {
                if ((m + n) % 2 == 0) {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                } else {
                    return max(l1, l2);
                }
            } else if (l1 > r2) {
                r = cut1 - 1;
            } else {
                l = cut1 + 1;
            }
        }
        return 0.0;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> a = {1, 3}, b = {2}; double res = s.findMedianSortedArrays(a, b);

    cout << "Passed test for Median of Two Sorted Arrays" << endl;
    return 0;
}
