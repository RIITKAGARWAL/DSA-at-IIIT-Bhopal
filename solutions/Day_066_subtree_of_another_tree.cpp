/**
 * Problem: Subtree of Another Tree
 * Day: 66 / 288
 * Category: Trees
 * Approach: Tree serialization or simultaneous DFS
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

struct TreeNode { int val; TreeNode *left, *right; TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} };
class Solution {
    bool isSame(TreeNode* s, TreeNode* t) {
        if (!s && !t) return true;
        if (!s || !t || s->val != t->val) return false;
        return isSame(s->left, t->left) && isSame(s->right, t->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!subRoot) return true;
        if (!root) return false;
        if (isSame(root, subRoot)) return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    TreeNode r(1), sub(1); bool res = s.isSubtree(&r, &sub);

    cout << "Passed test for Subtree of Another Tree" << endl;
    return 0;
}
