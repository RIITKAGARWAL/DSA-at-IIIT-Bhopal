/**
 * Problem: Remove Duplicates from Sorted Array
 * Day: 22 / 288
 * Category: Two Pointers
 * Approach: In-place overwrite pointer
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int i = 0;
        for (int j = 1; j < (int)nums.size(); ++j) {
            if (nums[j] != nums[i]) {
                nums[++i] = nums[j];
            }
        }
        return i + 1;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4}; int res = s.removeDuplicates(nums);

    cout << "Passed test for Remove Duplicates from Sorted Array" << endl;
    return 0;
}
