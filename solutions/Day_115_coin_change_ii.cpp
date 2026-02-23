/**
 * Problem: Coin Change II
 * Day: 115 / 288
 * Category: Dynamic Programming
 * Approach: Unbounded knapsack number of combinations
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int coin : coins) {
            for (int i = coin; i <= amount; ++i) {
                dp[i] += dp[i - coin];
            }
        }
        return dp[amount];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> coins = {1, 2, 5}; int res = s.change(5, coins);

    cout << "Passed test for Coin Change II" << endl;
    return 0;
}
