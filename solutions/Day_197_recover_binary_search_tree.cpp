/**
 * Problem: Recover Binary Search Tree
 * Day: 197 / 288
 * Category: BST
 * Approach: Inorder anomaly detection
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

struct TreeNode { int val; TreeNode *left, *right; TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} };
class Solution {
    TreeNode *first = nullptr, *second = nullptr, *prev = nullptr;
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        if (prev && root->val < prev->val) {
            if (!first) first = prev;
            second = root;
        }
        prev = root;
        inorder(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        inorder(root);
        if (first && second) swap(first->val, second->val);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    TreeNode root(3); root.left = new TreeNode(1); root.right = new TreeNode(4); root.right->left = new TreeNode(2); s.recoverTree(&root);

    cout << "Passed test for Recover Binary Search Tree" << endl;
    return 0;
}
