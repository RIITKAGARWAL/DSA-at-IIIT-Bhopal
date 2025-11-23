/**
 * Problem: Remove Duplicates from Sorted Array II
 * Day: 23 / 288
 * Category: Two Pointers
 * Approach: At-most-2 duplicate write pointer
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;
        int writeIdx = 2;
        for (int i = 2; i < n; ++i) {
            if (nums[i] != nums[writeIdx - 2]) {
                nums[writeIdx++] = nums[i];
            }
        }
        return writeIdx;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> nums = {1, 1, 1, 2, 2, 3}; int res = s.removeDuplicates(nums);

    cout << "Passed test for Remove Duplicates from Sorted Array II" << endl;
    return 0;
}
