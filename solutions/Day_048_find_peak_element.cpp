/**
 * Problem: Find Peak Element
 * Day: 48 / 288
 * Category: Binary Search
 * Approach: Slope gradient binary search
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < nums[mid + 1]) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> a = {1, 2, 3, 1}; int res = s.findPeakElement(a);

    cout << "Passed test for Find Peak Element" << endl;
    return 0;
}
