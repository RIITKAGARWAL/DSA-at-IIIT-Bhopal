/**
 * Problem: Stream of Characters
 * Day: 214 / 288
 * Category: Trie
 * Approach: Reverse suffix Trie stream matching
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class StreamChecker {
    struct TrieNode {
        TrieNode* children[26] = {nullptr};
        bool isEnd = false;
    };
    TrieNode* root = new TrieNode();
    string stream = "";
    void insert(string s) {
        TrieNode* curr = root;
        for (int i = s.size() - 1; i >= 0; --i) {
            char c = s[i];
            if (!curr->children[c - 'a']) curr->children[c - 'a'] = new TrieNode();
            curr = curr->children[c - 'a'];
        }
        curr->isEnd = true;
    }
public:
    StreamChecker(vector<string>& words) {
        for (string& w : words) insert(w);
    }
    bool query(char letter) {
        stream += letter;
        TrieNode* curr = root;
        for (int i = stream.size() - 1; i >= 0; --i) {
            char c = stream[i];
            if (!curr->children[c - 'a']) return false;
            curr = curr->children[c - 'a'];
            if (curr->isEnd) return true;
        }
        return false;
    }
};
class Solution {
public:
    void test() {
        vector<string> words = {"cd", "f", "kl"};
        StreamChecker sc(words);
        sc.query('a');
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    s.test();

    cout << "Passed test for Stream of Characters" << endl;
    return 0;
}
