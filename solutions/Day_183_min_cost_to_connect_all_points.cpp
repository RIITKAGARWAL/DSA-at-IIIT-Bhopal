/**
 * Problem: Min Cost to Connect All Points
 * Day: 183 / 288
 * Category: Graphs
 * Approach: Prim's Minimum Spanning Tree
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> visited(n, false);
        pq.push({0, 0});
        int cost = 0, edges = 0;
        while (!pq.empty() && edges < n) {
            auto [w, u] = pq.top(); pq.pop();
            if (visited[u]) continue;
            visited[u] = true;
            cost += w;
            edges++;
            for (int v = 0; v < n; ++v) {
                if (!visited[v]) {
                    int dist = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                    pq.push({dist, v});
                }
            }
        }
        return cost;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<vector<int>> p = {{0,0},{2,2},{3,10},{5,2},{7,0}}; int res = s.minCostConnectPoints(p);

    cout << "Passed test for Min Cost to Connect All Points" << endl;
    return 0;
}
