/**
 * Problem: Network Delay Time
 * Day: 176 / 288
 * Category: Graphs
 * Approach: Dijkstra's Algorithm
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& t : times) adj[t[0]].push_back({t[1], t[2]});
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n + 1, 1e9);
        pq.push({0, k});
        dist[k] = 0;
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;
            for (auto& edge : adj[u]) {
                int v = edge.first, w = edge.second;
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        int maxDist = 0;
        for (int i = 1; i <= n; ++i) maxDist = max(maxDist, dist[i]);
        return maxDist == 1e9 ? -1 : maxDist;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}}; int res = s.networkDelayTime(times, 4, 2);

    cout << "Passed test for Network Delay Time" << endl;
    return 0;
}
