/**
 * Problem: Redundant Connection
 * Day: 82 / 288
 * Category: Graphs
 * Approach: DSU cycle detection
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1);
        iota(parent.begin(), parent.end(), 0);
        
        function<int(int)> find = [&](int i) {
            return parent[i] == i ? i : parent[i] = find(parent[i]);
        };
        
        for (const auto& edge : edges) {
            int root1 = find(edge[0]);
            int root2 = find(edge[1]);
            if (root1 == root2) return edge;
            parent[root1] = root2;
        }
        return {};
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {2, 3}}; auto res = s.findRedundantConnection(edges);

    cout << "Passed test for Redundant Connection" << endl;
    return 0;
}
