/**
 * Problem: Validate Binary Search Tree
 * Day: 69 / 288
 * Category: BST
 * Approach: Min-max valid interval propagation
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

struct TreeNode { int val; TreeNode *left, *right; TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} };
class Solution {
    bool isValid(TreeNode* root, long minVal, long maxVal) {
        if (!root) return true;
        if (root->val <= minVal || root->val >= maxVal) return false;
        return isValid(root->left, minVal, root->val) && isValid(root->right, root->val, maxVal);
    }
public:
    bool isValidBST(TreeNode* root) {
        return isValid(root, LONG_MIN, LONG_MAX);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    TreeNode root(2); bool res = s.isValidBST(&root);

    cout << "Passed test for Validate Binary Search Tree" << endl;
    return 0;
}
