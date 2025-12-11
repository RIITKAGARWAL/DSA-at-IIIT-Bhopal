/**
 * Problem: Binary Search
 * Day: 41 / 288
 * Category: Binary Search
 * Approach: Standard lower/upper bound iteration
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
            if (nums[mid] < target) l = mid + 1;
            else r = mid - 1;
        }
        return -1;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> a = {-1, 0, 3, 5, 9, 12}; int res = s.search(a, 9);

    cout << "Passed test for Binary Search" << endl;
    return 0;
}
