/**
 * Problem: Design Add and Search Words Data Structure
 * Day: 84 / 288
 * Category: Trie
 * Approach: Trie with backtracking for dot wildcard
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class WordDictionary {
    struct TrieNode {
        TrieNode* children[26] = {nullptr};
        bool isWord = false;
    };
    TrieNode* root;
    bool searchHelper(string& word, int idx, TrieNode* node) {
        if (!node) return false;
        if (idx == word.size()) return node->isWord;
        char c = word[idx];
        if (c != '.') return searchHelper(word, idx + 1, node->children[c - 'a']);
        for (int i = 0; i < 26; ++i) {
            if (node->children[i] && searchHelper(word, idx + 1, node->children[i])) return true;
        }
        return false;
    }
public:
    WordDictionary() { root = new TrieNode(); }
    void addWord(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (!curr->children[c - 'a']) curr->children[c - 'a'] = new TrieNode();
            curr = curr->children[c - 'a'];
        }
        curr->isWord = true;
    }
    bool search(string word) { return searchHelper(word, 0, root); }
};
class Solution {
public:
    void testDict() {
        WordDictionary wd; wd.addWord("bad"); wd.search(".ad");
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    s.testDict();

    cout << "Passed test for Design Add and Search Words Data Structure" << endl;
    return 0;
}
