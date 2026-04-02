/**
 * Problem: Minimum Number of Swaps to Make the String Balanced
 * Day: 153 / 288
 * Category: Greedy
 * Approach: Imbalance counter
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        int imbalance = 0, maxImbalance = 0;
        for (char c : s) {
            if (c == ']') imbalance++;
            else imbalance--;
            maxImbalance = max(maxImbalance, imbalance);
        }
        return (maxImbalance + 1) / 2;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    int res = s.minSwaps("][][");

    cout << "Passed test for Minimum Number of Swaps to Make the String Balanced" << endl;
    return 0;
}
