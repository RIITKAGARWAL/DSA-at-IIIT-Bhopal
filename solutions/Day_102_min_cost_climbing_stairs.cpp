/**
 * Problem: Min Cost Climbing Stairs
 * Day: 102 / 288
 * Category: Dynamic Programming
 * Approach: Running step minimum cost 1D DP
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int prev2 = cost[0];
        int prev1 = cost[1];
        for (int i = 2; i < n; ++i) {
            int curr = cost[i] + min(prev1, prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        return min(prev1, prev2);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> cost = {10, 15, 20}; int res = s.minCostClimbingStairs(cost);

    cout << "Passed test for Min Cost Climbing Stairs" << endl;
    return 0;
}
