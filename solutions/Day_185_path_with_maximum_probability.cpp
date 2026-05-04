/**
 * Problem: Path with Maximum Probability
 * Day: 185 / 288
 * Category: Graphs
 * Approach: Max-Heap Dijkstra
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i < edges.size(); ++i) {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        priority_queue<pair<double, int>> pq;
        vector<double> probs(n, 0.0);
        pq.push({1.0, start});
        probs[start] = 1.0;
        while (!pq.empty()) {
            auto [p, u] = pq.top(); pq.pop();
            if (u == end) return p;
            if (p < probs[u]) continue;
            for (auto& edge : adj[u]) {
                int v = edge.first; double prob = edge.second;
                if (p * prob > probs[v]) {
                    probs[v] = p * prob;
                    pq.push({probs[v], v});
                }
            }
        }
        return 0.0;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<vector<int>> e = {{0,1},{1,2},{0,2}}; vector<double> p = {0.5,0.5,0.2}; double res = s.maxProbability(3, e, p, 0, 2);

    cout << "Passed test for Path with Maximum Probability" << endl;
    return 0;
}
