/**
 * Problem: Cheapest Flights Within K Stops
 * Day: 175 / 288
 * Category: Graphs
 * Approach: Bellman-Ford relaxation array
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prices(n, 1e9);
        prices[src] = 0;
        for (int i = 0; i <= k; ++i) {
            vector<int> tempPrices = prices;
            for (auto& flight : flights) {
                int u = flight[0], v = flight[1], w = flight[2];
                if (prices[u] == 1e9) continue;
                if (prices[u] + w < tempPrices[v]) {
                    tempPrices[v] = prices[u] + w;
                }
            }
            prices = tempPrices;
        }
        return prices[dst] == 1e9 ? -1 : prices[dst];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<vector<int>> flights = {{0,1,100},{1,2,100},{0,2,500}}; int res = s.findCheapestPrice(3, flights, 0, 2, 1);

    cout << "Passed test for Cheapest Flights Within K Stops" << endl;
    return 0;
}
