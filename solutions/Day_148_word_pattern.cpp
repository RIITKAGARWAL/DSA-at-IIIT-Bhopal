/**
 * Problem: Word Pattern
 * Day: 148 / 288
 * Category: Hash Table
 * Approach: Two-way bijection Hash Map
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> char2word;
        unordered_map<string, char> word2char;
        stringstream ss(s);
        string word;
        int i = 0, n = pattern.size();
        while (ss >> word) {
            if (i == n) return false;
            char c = pattern[i];
            if (char2word.count(c) && char2word[c] != word) return false;
            if (word2char.count(word) && word2char[word] != c) return false;
            char2word[c] = word;
            word2char[word] = c;
            i++;
        }
        return i == n;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    bool res = s.wordPattern("abba", "dog cat cat dog");

    cout << "Passed test for Word Pattern" << endl;
    return 0;
}
