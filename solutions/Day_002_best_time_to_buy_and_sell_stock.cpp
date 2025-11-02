/**
 * Problem: Best Time to Buy and Sell Stock
 * Day: 2 / 288
 * Category: Arrays
 * Approach: One pass min price tracking
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX, maxP = 0;
        for (int p : prices) {
            minPrice = min(minPrice, p);
            maxP = max(maxP, p - minPrice);
        }
        return maxP;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> p = {7, 1, 5, 3, 6, 4}; int res = s.maxProfit(p);

    cout << "Passed test for Best Time to Buy and Sell Stock" << endl;
    return 0;
}
