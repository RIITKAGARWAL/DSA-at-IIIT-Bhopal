#include <vector>
#include <string>
using namespace std;
class Solution {
    bool dfs(int r, int c, int idx, vector<vector<char>>& b, const string& w) {
        if (idx == w.size()) return true;
        if (r < 0 || c < 0 || r >= b.size() || c >= b[0].size() || b[r][c] != w[idx]) return false;
        char temp = b[r][c];
        b[r][c] = '#';
        bool found = dfs(r+1, c, idx+1, b, w) || dfs(r-1, c, idx+1, b, w) ||
                     dfs(r, c+1, idx+1, b, w) || dfs(r, c-1, idx+1, b, w);
        b[r][c] = temp;
        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (dfs(i, j, 0, board, word)) return true;
            }
        }
        return false;
    }
};