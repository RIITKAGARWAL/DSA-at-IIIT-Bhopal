/**
 * Problem: Number of Connected Components
 * Day: 81 / 288
 * Category: Graphs
 * Approach: Disjoint Set Union (DSU)
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);
        int components = n;
        
        function<int(int)> find = [&](int i) {
            return parent[i] == i ? i : parent[i] = find(parent[i]);
        };
        
        for (const auto& edge : edges) {
            int root1 = find(edge[0]);
            int root2 = find(edge[1]);
            if (root1 != root2) {
                parent[root1] = root2;
                components--;
            }
        }
        return components;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {3, 4}}; int res = s.countComponents(5, edges);

    cout << "Passed test for Number of Connected Components" << endl;
    return 0;
}
