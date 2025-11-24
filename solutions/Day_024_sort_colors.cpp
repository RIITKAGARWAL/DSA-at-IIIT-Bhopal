/**
 * Problem: Sort Colors
 * Day: 24 / 288
 * Category: Arrays
 * Approach: Dutch National Flag 3-way partition
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = (int)nums.size() - 1;
        while (mid <= high) {
            if (nums[mid] == 0) swap(nums[low++], nums[mid++]);
            else if (nums[mid] == 1) mid++;
            else swap(nums[mid], nums[high--]);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> nums = {2, 0, 2, 1, 1, 0}; s.sortColors(nums);

    cout << "Passed test for Sort Colors" << endl;
    return 0;
}
