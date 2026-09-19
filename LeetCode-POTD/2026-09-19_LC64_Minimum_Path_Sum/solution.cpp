#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    int dfs(int r, int c, const vector<vector<int>>& g) {
        if (r == g.size() - 1 && c == g[0].size() - 1) return g[r][c];
        if (r >= g.size() || c >= g[0].size()) return 1e9;
        return g[r][c] + min(dfs(r + 1, c, g), dfs(r, c + 1, g));
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        return dfs(0, 0, grid);
    }
};