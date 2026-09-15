#include <vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty()) return res;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<bool>> seen(m, vector<bool>(n, false));
        int dr[] = {0, 1, 0, -1}, dc[] = {1, 0, -1, 0};
        int r = 0, c = 0, di = 0;
        for (int i = 0; i < m * n; ++i) {
            res.push_back(matrix[r][c]);
            seen[r][c] = true;
            int cr = r + dr[di], cc = c + dc[di];
            if (cr >= 0 && cr < m && cc >= 0 && cc < n && !seen[cr][cc]) {
                r = cr; c = cc;
            } else {
                di = (di + 1) % 4;
                r += dr[di]; c += dc[di];
            }
        }
        return res;
    }
};