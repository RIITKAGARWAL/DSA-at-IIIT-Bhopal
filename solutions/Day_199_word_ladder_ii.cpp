/**
 * Problem: Word Ladder II
 * Day: 199 / 288
 * Category: Graphs
 * Approach: BFS for shortest path DAG + DFS Backtracking
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(string word, string endWord, unordered_map<string, vector<string>>& adj, vector<string>& path, vector<vector<string>>& res) {
        path.push_back(word);
        if (word == endWord) res.push_back(path);
        else {
            for (string next : adj[word]) dfs(next, endWord, adj, path, res);
        }
        path.pop_back();
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return {};
        unordered_map<string, vector<string>> adj;
        unordered_set<string> currLevel = {beginWord};
        bool found = false;
        while (!currLevel.empty() && !found) {
            for (string w : currLevel) dict.erase(w);
            unordered_set<string> nextLevel;
            for (string w : currLevel) {
                string orig = w;
                for (int i = 0; i < w.size(); ++i) {
                    char c = w[i];
                    for (char x = 'a'; x <= 'z'; ++x) {
                        w[i] = x;
                        if (dict.count(w)) {
                            adj[orig].push_back(w);
                            nextLevel.insert(w);
                            if (w == endWord) found = true;
                        }
                    }
                    w[i] = c;
                }
            }
            currLevel = nextLevel;
        }
        vector<vector<string>> res;
        vector<string> path;
        dfs(beginWord, endWord, adj, path, res);
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<string> w = {"hot","dot","dog","lot","log","cog"}; auto res = s.findLadders("hit", "cog", w);

    cout << "Passed test for Word Ladder II" << endl;
    return 0;
}
