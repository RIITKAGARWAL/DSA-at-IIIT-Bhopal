/**
 * Problem: Lowest Common Ancestor of a Binary Tree
 * Day: 195 / 288
 * Category: Trees
 * Approach: Post-order recursive bubbling
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

struct TreeNode { int val; TreeNode *left, *right; TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} };
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left && right) return root;
        return left ? left : right;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    TreeNode root(3), p(5), q(1); root.left = &p; root.right = &q; auto res = s.lowestCommonAncestor(&root, &p, &q);

    cout << "Passed test for Lowest Common Ancestor of a Binary Tree" << endl;
    return 0;
}
