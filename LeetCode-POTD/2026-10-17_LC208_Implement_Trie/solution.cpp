#include <string>
#include <vector>
using namespace std;
class Trie {
    struct Node {
        Node* children[26] = {nullptr};
        bool isEnd = false;
    };
    Node* root;
public:
    Trie() { root = new Node(); }
    void insert(string word) {
        Node* cur = root;
        for (char c : word) {
            if (!cur->children[c - 'a']) cur->children[c - 'a'] = new Node();
            cur = cur->children[c - 'a'];
        }
        cur->isEnd = true;
    }
    bool search(string word) {
        Node* cur = root;
        for (char c : word) {
            if (!cur->children[c - 'a']) return false;
            cur = cur->children[c - 'a'];
        }
        return cur->isEnd;
    }
    bool startsWith(string prefix) {
        Node* cur = root;
        for (char c : prefix) {
            if (!cur->children[c - 'a']) return false;
            cur = cur->children[c - 'a'];
        }
        return true;
    }
};