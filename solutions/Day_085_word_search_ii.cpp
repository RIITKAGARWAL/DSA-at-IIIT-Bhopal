/**
 * Problem: Word Search II
 * Day: 85 / 288
 * Category: Trie
 * Approach: Trie prefix pruning + Grid DFS
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct TrieNode {
        TrieNode* children[26] = {nullptr};
        string word = "";
    };
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* p, vector<string>& res) {
        char c = board[i][j];
        if (c == '#' || !p->children[c - 'a']) return;
        p = p->children[c - 'a'];
        if (p->word != "") { res.push_back(p->word); p->word = ""; }
        board[i][j] = '#';
        if (i > 0) dfs(board, i - 1, j, p, res);
        if (j > 0) dfs(board, i, j - 1, p, res);
        if (i < board.size() - 1) dfs(board, i + 1, j, p, res);
        if (j < board[0].size() - 1) dfs(board, i, j + 1, p, res);
        board[i][j] = c;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (string& w : words) {
            TrieNode* p = root;
            for (char c : w) {
                if (!p->children[c - 'a']) p->children[c - 'a'] = new TrieNode();
                p = p->children[c - 'a'];
            }
            p->word = w;
        }
        vector<string> res;
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[0].size(); ++j)
                dfs(board, i, j, root, res);
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<vector<char>> b = {{'o','a'}, {'e','t'}}; vector<string> w = {"oat", "pea"}; auto res = s.findWords(b, w);

    cout << "Passed test for Word Search II" << endl;
    return 0;
}
