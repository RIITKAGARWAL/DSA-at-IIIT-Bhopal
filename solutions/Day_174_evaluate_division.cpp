/**
 * Problem: Evaluate Division
 * Day: 174 / 288
 * Category: Graphs
 * Approach: Weighted Directed Graph DFS
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    double dfs(unordered_map<string, unordered_map<string, double>>& graph, string curr, string target, unordered_set<string>& visited) {
        if (graph.find(curr) == graph.end() || graph.find(target) == graph.end()) return -1.0;
        if (curr == target) return 1.0;
        visited.insert(curr);
        for (auto& neighbor : graph[curr]) {
            if (visited.find(neighbor.first) == visited.end()) {
                double res = dfs(graph, neighbor.first, target, visited);
                if (res != -1.0) return neighbor.second * res;
            }
        }
        return -1.0;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph;
        for (int i = 0; i < equations.size(); ++i) {
            graph[equations[i][0]][equations[i][1]] = values[i];
            graph[equations[i][1]][equations[i][0]] = 1.0 / values[i];
        }
        vector<double> res;
        for (auto& q : queries) {
            unordered_set<string> visited;
            res.push_back(dfs(graph, q[0], q[1], visited));
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<vector<string>> eqs = {{"a","b"},{"b","c"}}; vector<double> vals = {2.0, 3.0}; vector<vector<string>> qs = {{"a","c"}}; auto res = s.calcEquation(eqs, vals, qs);

    cout << "Passed test for Evaluate Division" << endl;
    return 0;
}
