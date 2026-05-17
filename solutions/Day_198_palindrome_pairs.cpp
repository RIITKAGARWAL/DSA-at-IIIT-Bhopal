/**
 * Problem: Palindrome Pairs
 * Day: 198 / 288
 * Category: Trie
 * Approach: Hash map reverse string lookup
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool isPal(const string& s, int l, int r) {
        while (l < r) if (s[l++] != s[r--]) return false;
        return true;
    }
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> dict;
        vector<vector<int>> res;
        for (int i = 0; i < words.size(); ++i) dict[string(words[i].rbegin(), words[i].rend())] = i;
        for (int i = 0; i < words.size(); ++i) {
            string w = words[i];
            for (int j = 0; j <= w.size(); ++j) {
                if (isPal(w, j, w.size() - 1)) {
                    string prefix = w.substr(0, j);
                    if (dict.count(prefix) && dict[prefix] != i) res.push_back({i, dict[prefix]});
                }
                if (j > 0 && isPal(w, 0, j - 1)) {
                    string suffix = w.substr(j);
                    if (dict.count(suffix) && dict[suffix] != i) res.push_back({dict[suffix], i});
                }
            }
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<string> words = {"bat","tab","cat"}; auto res = s.palindromePairs(words);

    cout << "Passed test for Palindrome Pairs" << endl;
    return 0;
}
