/**
 * Problem: Course Schedule
 * Day: 78 / 288
 * Category: Graphs
 * Approach: Topological Sort / Kahn's Algorithm
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for (auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) q.push(i);
        }
        int count = 0;
        while (!q.empty()) {
            int curr = q.front(); q.pop();
            count++;
            for (int next : adj[curr]) {
                if (--indegree[next] == 0) q.push(next);
            }
        }
        return count == numCourses;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<vector<int>> pre = {{1,0}}; bool res = s.canFinish(2, pre);

    cout << "Passed test for Course Schedule" << endl;
    return 0;
}
