/**
 * Problem: Longest Consecutive Sequence
 * Day: 18 / 288
 * Category: Arrays
 * Approach: Hash Set sequence boundary checking
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;
        for (int num : numSet) {
            if (!numSet.count(num - 1)) {
                int cur = num, streak = 1;
                while (numSet.count(cur + 1)) {
                    cur++;
                    streak++;
                }
                longest = max(longest, streak);
            }
        }
        return longest;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> nums = {100, 4, 200, 1, 3, 2}; int res = s.longestConsecutive(nums);

    cout << "Passed test for Longest Consecutive Sequence" << endl;
    return 0;
}
