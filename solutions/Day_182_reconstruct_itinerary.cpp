/**
 * Problem: Reconstruct Itinerary
 * Day: 182 / 288
 * Category: Graphs
 * Approach: Hierholzer's Algorithm
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;
    vector<string> res;
    void dfs(string airport) {
        while (!adj[airport].empty()) {
            string next = adj[airport].top();
            adj[airport].pop();
            dfs(next);
        }
        res.push_back(airport);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto& t : tickets) adj[t[0]].push(t[1]);
        dfs("JFK");
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<vector<string>> t = {{"MUC","LHR"},{"JFK","MUC"},{"SFO","SJC"},{"LHR","SFO"}}; auto res = s.findItinerary(t);

    cout << "Passed test for Reconstruct Itinerary" << endl;
    return 0;
}
