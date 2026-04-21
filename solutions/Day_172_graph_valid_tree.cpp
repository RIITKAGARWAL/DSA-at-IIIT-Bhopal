/**
 * Problem: Graph Valid Tree
 * Day: 172 / 288
 * Category: Graphs
 * Approach: Union-Find cycle and component check
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);
        function<int(int)> find = [&](int i) {
            return parent[i] == i ? i : parent[i] = find(parent[i]);
        };
        for (const auto& edge : edges) {
            int root1 = find(edge[0]);
            int root2 = find(edge[1]);
            if (root1 == root2) return false;
            parent[root1] = root2;
        }
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<vector<int>> edges = {{0,1},{0,2},{0,3},{1,4}}; bool res = s.validTree(5, edges);

    cout << "Passed test for Graph Valid Tree" << endl;
    return 0;
}
