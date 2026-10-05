#include <string>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return 0;
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        while (!q.empty()) {
            auto [word, len] = q.front(); q.pop();
            if (word == endWord) return len;
            for (int i = 0; i < word.size(); ++i) {
                char orig = word[i];
                for (char c = 'a'; c <= 'z'; ++c) {
                    word[i] = c;
                    if (dict.count(word)) {
                        dict.erase(word);
                        q.push({word, len + 1});
                    }
                }
                word[i] = orig;
            }
        }
        return 0;
    }
};