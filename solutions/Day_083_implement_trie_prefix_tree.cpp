/**
 * Problem: Implement Trie Prefix Tree
 * Day: 83 / 288
 * Category: Trie
 * Approach: 26-ary prefix tree
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Trie {
    struct TrieNode {
        TrieNode* children[26] = {nullptr};
        bool isEndOfWord = false;
    };
    TrieNode* root;
public:
    Trie() { root = new TrieNode(); }
    void insert(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (!curr->children[c - 'a']) curr->children[c - 'a'] = new TrieNode();
            curr = curr->children[c - 'a'];
        }
        curr->isEndOfWord = true;
    }
    bool search(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (!curr->children[c - 'a']) return false;
            curr = curr->children[c - 'a'];
        }
        return curr->isEndOfWord;
    }
};
class Solution {
public:
    void testTrie() {
        Trie t; t.insert("apple"); t.search("apple");
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    s.testTrie();

    cout << "Passed test for Implement Trie Prefix Tree" << endl;
    return 0;
}
