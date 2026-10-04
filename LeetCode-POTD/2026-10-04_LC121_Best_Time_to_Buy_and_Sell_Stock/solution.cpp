#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0, n = prices.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                maxP = max(maxP, prices[j] - prices[i]);
            }
        }
        return maxP;
    }
};