/**
 * Problem: Longest Increasing Subsequence
 * Day: 110 / 288
 * Category: Dynamic Programming
 * Approach: Patience sorting / Binary search O(n log n)
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for (int num : nums) {
            auto it = lower_bound(res.begin(), res.end(), num);
            if (it == res.end()) res.push_back(num);
            else *it = num;
        }
        return res.size();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18}; int res = s.lengthOfLIS(nums);

    cout << "Passed test for Longest Increasing Subsequence" << endl;
    return 0;
}
