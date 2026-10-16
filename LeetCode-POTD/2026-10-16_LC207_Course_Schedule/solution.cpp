#include <vector>
using namespace std;
class Solution {
    bool hasCycle(int u, vector<int>& state, const vector<vector<int>>& adj) {
        state[u] = 1;
        for (int v : adj[u]) {
            if (state[v] == 1) return true;
            if (state[v] == 0 && hasCycle(v, state, adj)) return true;
        }
        state[u] = 2;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto& p : prerequisites) adj[p[1]].push_back(p[0]);
        vector<int> state(numCourses, 0);
        for (int i = 0; i < numCourses; ++i) {
            if (state[i] == 0 && hasCycle(i, state, adj)) return false;
        }
        return true;
    }
};