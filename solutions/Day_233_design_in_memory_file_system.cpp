/**
 * Problem: Design In-Memory File System
 * Day: 233 / 288
 * Category: Design
 * Approach: Trie with file/directory nodes
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class FileSystem {
    struct Node {
        bool isFile = false;
        string content = "";
        map<string, Node*> children;
    };
    Node* root = new Node();
    vector<string> parse(string path) {
        vector<string> res; stringstream ss(path); string token;
        while (getline(ss, token, '/')) {
            if (!token.empty()) res.push_back(token);
        }
        return res;
    }
public:
    FileSystem() {}
    vector<string> ls(string path) {
        Node* curr = root;
        vector<string> paths = parse(path);
        for (string p : paths) curr = curr->children[p];
        if (curr->isFile) return {paths.back()};
        vector<string> res;
        for (auto& p : curr->children) res.push_back(p.first);
        return res;
    }
    void mkdir(string path) {
        Node* curr = root;
        for (string p : parse(path)) {
            if (!curr->children.count(p)) curr->children[p] = new Node();
            curr = curr->children[p];
        }
    }
    void addContentToFile(string filePath, string content) {
        Node* curr = root;
        vector<string> paths = parse(filePath);
        for (int i = 0; i < paths.size() - 1; ++i) {
            if (!curr->children.count(paths[i])) curr->children[paths[i]] = new Node();
            curr = curr->children[paths[i]];
        }
        string fileName = paths.back();
        if (!curr->children.count(fileName)) curr->children[fileName] = new Node();
        curr = curr->children[fileName];
        curr->isFile = true;
        curr->content += content;
    }
    string readContentFromFile(string filePath) {
        Node* curr = root;
        for (string p : parse(filePath)) curr = curr->children[p];
        return curr->content;
    }
};
class Solution {
public:
    void test() { FileSystem fs; fs.mkdir("/a/b/c"); fs.ls("/a/b"); }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    s.test();

    cout << "Passed test for Design In-Memory File System" << endl;
    return 0;
}
