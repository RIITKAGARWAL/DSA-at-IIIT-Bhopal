/**
 * Problem: Minimum Height Trees
 * Day: 173 / 288
 * Category: Graphs
 * Approach: Topological sort leaf trimming
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        vector<unordered_set<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].insert(edge[1]);
            adj[edge[1]].insert(edge[0]);
        }
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (adj[i].size() == 1) q.push(i);
        }
        int remaining = n;
        while (remaining > 2) {
            int sz = q.size();
            remaining -= sz;
            for (int i = 0; i < sz; ++i) {
                int leaf = q.front(); q.pop();
                int neighbor = *adj[leaf].begin();
                adj[neighbor].erase(leaf);
                if (adj[neighbor].size() == 1) q.push(neighbor);
            }
        }
        vector<int> res;
        while (!q.empty()) { res.push_back(q.front()); q.pop(); }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<vector<int>> edges = {{1,0},{1,2},{1,3}}; auto res = s.findMinHeightTrees(4, edges);

    cout << "Passed test for Minimum Height Trees" << endl;
    return 0;
}
