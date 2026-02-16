/**
 * Problem: Coin Change
 * Day: 108 / 288
 * Category: Dynamic Programming
 * Approach: Unbounded Knapsack bottom-up
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int coin : coins) {
                if (i - coin >= 0) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> coins = {1, 2, 5}; int res = s.coinChange(coins, 11);

    cout << "Passed test for Coin Change" << endl;
    return 0;
}
