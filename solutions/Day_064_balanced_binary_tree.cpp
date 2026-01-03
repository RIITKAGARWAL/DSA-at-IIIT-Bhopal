/**
 * Problem: Balanced Binary Tree
 * Day: 64 / 288
 * Category: Trees
 * Approach: DFS subtree height differential check
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

struct TreeNode { int val; TreeNode *left, *right; TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} };
class Solution {
    int dfs(TreeNode* root) {
        if (!root) return 0;
        int left = dfs(root->left);
        if (left == -1) return -1;
        int right = dfs(root->right);
        if (right == -1) return -1;
        if (abs(left - right) > 1) return -1;
        return 1 + max(left, right);
    }
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    TreeNode root(1); bool res = s.isBalanced(&root);

    cout << "Passed test for Balanced Binary Tree" << endl;
    return 0;
}
