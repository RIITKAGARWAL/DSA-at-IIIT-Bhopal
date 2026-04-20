/**
 * Problem: Course Schedule II
 * Day: 171 / 288
 * Category: Graphs
 * Approach: Topological Sort / Kahn's Algorithm
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for (const auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) q.push(i);
        }
        vector<int> res;
        while (!q.empty()) {
            int curr = q.front(); q.pop();
            res.push_back(curr);
            for (int next : adj[curr]) {
                if (--indegree[next] == 0) q.push(next);
            }
        }
        return res.size() == numCourses ? res : vector<int>();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<vector<int>> pre = {{1,0},{2,0},{3,1},{3,2}}; auto res = s.findOrder(4, pre);

    cout << "Passed test for Course Schedule II" << endl;
    return 0;
}
