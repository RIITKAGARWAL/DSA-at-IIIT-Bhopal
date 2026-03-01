/**
 * Problem: Jump Game
 * Day: 121 / 288
 * Category: Greedy
 * Approach: Track maximum reachable index
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > maxReach) return false;
            maxReach = max(maxReach, i + nums[i]);
        }
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> nums = {2, 3, 1, 1, 4}; bool res = s.canJump(nums);

    cout << "Passed test for Jump Game" << endl;
    return 0;
}
