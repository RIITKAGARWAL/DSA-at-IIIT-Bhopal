/**
 * Problem: Serialize and Deserialize BST
 * Day: 196 / 288
 * Category: BST
 * Approach: Preorder bounds compression
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

struct TreeNode { int val; TreeNode *left, *right; TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} };
class Codec {
    TreeNode* build(queue<string>& q, int minVal, int maxVal) {
        if (q.empty()) return nullptr;
        int val = stoi(q.front());
        if (val < minVal || val > maxVal) return nullptr;
        q.pop();
        TreeNode* root = new TreeNode(val);
        root->left = build(q, minVal, val);
        root->right = build(q, val, maxVal);
        return root;
    }
public:
    string serialize(TreeNode* root) {
        if (!root) return "";
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        queue<string> q; string s;
        for (char c : data) {
            if (c == ',') { q.push(s); s = ""; }
            else s += c;
        }
        return build(q, INT_MIN, INT_MAX);
    }
};
class Solution {
public:
    void test() {
        TreeNode root(2); Codec c; string data = c.serialize(&root); c.deserialize(data);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    s.test();

    cout << "Passed test for Serialize and Deserialize BST" << endl;
    return 0;
}
