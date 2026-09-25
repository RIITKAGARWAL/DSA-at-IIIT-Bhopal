#include <vector>
#include <string>
using namespace std;
class Solution {
    bool backtrack(vector<vector<char>>& board, const string& word, int idx, int r, int c) {
        if (idx == word.size()) return true;
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] != word[idx]) return false;
        board[r][c] ^= 256;
        int d[] = {-1, 0, 1, 0, -1};
        for (int k = 0; k < 4; ++k) {
            if (backtrack(board, word, idx + 1, r + d[k], c + d[k + 1])) return true;
        }
        board[r][c] ^= 256;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (backtrack(board, word, 0, i, j)) return true;
            }
        }
        return false;
    }
};