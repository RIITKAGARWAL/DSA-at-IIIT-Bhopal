/**
 * Problem: Kth Smallest Element in a BST
 * Day: 70 / 288
 * Category: BST
 * Approach: Inorder traversal counter termination
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

struct TreeNode { int val; TreeNode *left, *right; TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} };
class Solution {
    int count = 0;
    int result = -1;
    void inorder(TreeNode* root, int k) {
        if (!root) return;
        inorder(root->left, k);
        count++;
        if (count == k) {
            result = root->val;
            return;
        }
        inorder(root->right, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return result;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    TreeNode root(1); int res = s.kthSmallest(&root, 1);

    cout << "Passed test for Kth Smallest Element in a BST" << endl;
    return 0;
}
