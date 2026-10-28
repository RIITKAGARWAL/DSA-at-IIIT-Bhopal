#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    int solve(int amount, const vector<int>& coins) {
        if (amount == 0) return 0;
        if (amount < 0) return 1e9;
        int minC = 1e9;
        for (int c : coins) minC = min(minC, 1 + solve(amount - c, coins));
        return minC;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int ans = solve(amount, coins);
        return ans >= 1e9 ? -1 : ans;
    }
};