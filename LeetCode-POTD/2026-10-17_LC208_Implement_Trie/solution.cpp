#include <string>
using namespace std;
class Trie {
    struct TrieNode {
        TrieNode* next[26] = {};
        bool isTerminal = false;
    };
    TrieNode root;
public:
    Trie() {}
    void insert(string word) {
        TrieNode* p = &root;
        for (char c : word) {
            if (!p->next[c - 'a']) p->next[c - 'a'] = new TrieNode();
            p = p->next[c - 'a'];
        }
        p->isTerminal = true;
    }
    bool search(string word) {
        TrieNode* p = &root;
        for (char c : word) {
            if (!p->next[c - 'a']) return false;
            p = p->next[c - 'a'];
        }
        return p->isTerminal;
    }
    bool startsWith(string prefix) {
        TrieNode* p = &root;
        for (char c : prefix) {
            if (!p->next[c - 'a']) return false;
            p = p->next[c - 'a'];
        }
        return true;
    }
};