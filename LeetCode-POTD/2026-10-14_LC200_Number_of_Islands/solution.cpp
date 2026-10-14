#include <vector>
using namespace std;
class Solution {
    void bfs(vector<vector<char>>& g, int r, int c) {
        g[r][c] = '0';
        int d[] = {-1, 0, 1, 0, -1};
        for (int k = 0; k < 4; ++k) {
            int nr = r + d[k], nc = c + d[k + 1];
            if (nr >= 0 && nc >= 0 && nr < g.size() && nc < g[0].size() && g[nr][nc] == '1') {
                bfs(g, nr, nc);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    islands++;
                    bfs(grid, i, j);
                }
            }
        }
        return islands;
    }
};