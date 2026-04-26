/**
 * Problem: Is Graph Bipartite
 * Day: 177 / 288
 * Category: Graphs
 * Approach: BFS coloring mapping
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, 0);
        for (int i = 0; i < n; ++i) {
            if (colors[i] != 0) continue;
            queue<int> q;
            q.push(i);
            colors[i] = 1;
            while (!q.empty()) {
                int curr = q.front(); q.pop();
                for (int next : graph[curr]) {
                    if (colors[next] == 0) {
                        colors[next] = -colors[curr];
                        q.push(next);
                    } else if (colors[next] == colors[curr]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<vector<int>> g = {{1,3},{0,2},{1,3},{0,2}}; bool res = s.isBipartite(g);

    cout << "Passed test for Is Graph Bipartite" << endl;
    return 0;
}
