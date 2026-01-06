/**
 * Problem: Lowest Common Ancestor of a BST
 * Day: 67 / 288
 * Category: BST
 * Approach: Value divergence root steering
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

struct TreeNode { int val; TreeNode *left, *right; TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} };
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root) {
            if (p->val < root->val && q->val < root->val) root = root->left;
            else if (p->val > root->val && q->val > root->val) root = root->right;
            else return root;
        }
        return nullptr;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    TreeNode root(2), p(1), q(3); root.left = &p; root.right = &q; auto res = s.lowestCommonAncestor(&root, &p, &q);

    cout << "Passed test for Lowest Common Ancestor of a BST" << endl;
    return 0;
}
