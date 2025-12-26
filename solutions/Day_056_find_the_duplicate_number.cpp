/**
 * Problem: Find the Duplicate Number
 * Day: 56 / 288
 * Category: Linked List
 * Approach: Cycle detection in array
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[nums[0]];
        while (slow != fast) { slow = nums[slow]; fast = nums[nums[fast]]; }
        slow = 0;
        while (slow != fast) { slow = nums[slow]; fast = nums[fast]; }
        return slow;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> nums = {1, 3, 4, 2, 2}; int res = s.findDuplicate(nums);

    cout << "Passed test for Find the Duplicate Number" << endl;
    return 0;
}
