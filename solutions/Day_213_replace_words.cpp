/**
 * Problem: Replace Words
 * Day: 213 / 288
 * Category: Trie
 * Approach: Trie root replacement matching
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct TrieNode {
        TrieNode* children[26] = {nullptr};
        string word = "";
    };
    TrieNode* root = new TrieNode();
    void insert(string w) {
        TrieNode* curr = root;
        for (char c : w) {
            if (!curr->children[c - 'a']) curr->children[c - 'a'] = new TrieNode();
            curr = curr->children[c - 'a'];
        }
        curr->word = w;
    }
    string searchRoot(string w) {
        TrieNode* curr = root;
        for (char c : w) {
            if (!curr->children[c - 'a']) break;
            curr = curr->children[c - 'a'];
            if (curr->word != "") return curr->word;
        }
        return w;
    }
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        for (string& w : dictionary) insert(w);
        stringstream ss(sentence);
        string word, res = "";
        while (ss >> word) {
            if (!res.empty()) res += " ";
            res += searchRoot(word);
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<string> dict = {"cat", "bat", "rat"}; string s_in = "the cattle was rattled by the battery"; string res = s.replaceWords(dict, s_in);

    cout << "Passed test for Replace Words" << endl;
    return 0;
}
