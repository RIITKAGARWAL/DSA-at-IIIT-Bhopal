/**
 * Problem: Serialize and Deserialize Binary Tree
 * Day: 73 / 288
 * Category: Trees
 * Approach: Preorder traversal stringstream
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

struct TreeNode { int val; TreeNode *left, *right; TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} };
class Solution {
public:
    string serialize(TreeNode* root) {
        if (!root) return "N,";
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }
    TreeNode* deserialize(string data) {
        queue<string> q; string s;
        for (char c : data) {
            if (c == ',') { q.push(s); s = ""; }
            else s += c;
        }
        return build(q);
    }
    TreeNode* build(queue<string>& q) {
        string s = q.front(); q.pop();
        if (s == "N") return nullptr;
        TreeNode* root = new TreeNode(stoi(s));
        root->left = build(q);
        root->right = build(q);
        return root;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    TreeNode root(1); string data = s.serialize(&root); auto res = s.deserialize(data);

    cout << "Passed test for Serialize and Deserialize Binary Tree" << endl;
    return 0;
}
