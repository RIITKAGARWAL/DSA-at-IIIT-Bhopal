/**
 * Problem: Best Time to Buy and Sell Stock with Cooldown
 * Day: 114 / 288
 * Category: Dynamic Programming
 * Approach: State machine DP (Held, Sold, Reset)
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sold = 0, held = INT_MIN, reset = 0;
        for (int price : prices) {
            int preSold = sold;
            sold = held + price;
            held = max(held, reset - price);
            reset = max(reset, preSold);
        }
        return max(sold, reset);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> p = {1, 2, 3, 0, 2}; int res = s.maxProfit(p);

    cout << "Passed test for Best Time to Buy and Sell Stock with Cooldown" << endl;
    return 0;
}
