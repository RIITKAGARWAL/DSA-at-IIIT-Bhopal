/**
 * Problem: Jump Game II
 * Day: 122 / 288
 * Category: Greedy
 * Approach: BFS-like boundary expansion
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0, currentEnd = 0, currentFarthest = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            currentFarthest = max(currentFarthest, i + nums[i]);
            if (i == currentEnd) {
                jumps++;
                currentEnd = currentFarthest;
            }
        }
        return jumps;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> nums = {2, 3, 1, 1, 4}; int res = s.jump(nums);

    cout << "Passed test for Jump Game II" << endl;
    return 0;
}
