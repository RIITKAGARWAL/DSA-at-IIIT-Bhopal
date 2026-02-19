/**
 * Problem: Partition Equal Subset Sum
 * Day: 111 / 288
 * Category: Dynamic Programming
 * Approach: 0/1 Knapsack boolean subset sum
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int n : nums) sum += n;
        if (sum % 2 != 0) return false;
        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int n : nums) {
            for (int i = target; i >= n; --i) {
                dp[i] = dp[i] || dp[i - n];
            }
        }
        return dp[target];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> nums = {1, 5, 11, 5}; bool res = s.canPartition(nums);

    cout << "Passed test for Partition Equal Subset Sum" << endl;
    return 0;
}
