/**
 * Problem: Word Ladder
 * Day: 80 / 288
 * Category: Graphs
 * Approach: Bi-directional BFS transformation
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return 0;
        queue<string> q;
        q.push(beginWord);
        int level = 1;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                string word = q.front(); q.pop();
                if (word == endWord) return level;
                for (int j = 0; j < (int)word.size(); ++j) {
                    char orig = word[j];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        word[j] = c;
                        if (dict.count(word)) {
                            q.push(word);
                            dict.erase(word);
                        }
                    }
                    word[j] = orig;
                }
            }
            level++;
        }
        return 0;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<string> words = {"hot","dot","dog","lot","log","cog"}; int res = s.ladderLength("hit", "cog", words);

    cout << "Passed test for Word Ladder" << endl;
    return 0;
}
