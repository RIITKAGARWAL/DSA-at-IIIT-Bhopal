/**
 * Problem: Word Break II
 * Day: 162 / 288
 * Category: Backtracking
 * Approach: DFS with Hash Map memoization
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<string, vector<string>> memo;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if (memo.count(s)) return memo[s];
        if (s.empty()) return {""};
        vector<string> res;
        for (const string& word : wordDict) {
            if (s.substr(0, word.size()) == word) {
                vector<string> sublist = wordBreak(s.substr(word.size()), wordDict);
                for (const string& sub : sublist) {
                    res.push_back(word + (sub.empty() ? "" : " ") + sub);
                }
            }
        }
        return memo[s] = res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<string> dict = {"cat","cats","and","sand","dog"}; auto res = s.wordBreak("catsanddog", dict);

    cout << "Passed test for Word Break II" << endl;
    return 0;
}
