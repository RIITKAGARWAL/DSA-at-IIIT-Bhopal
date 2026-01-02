/**
 * Problem: Diameter of Binary Tree
 * Day: 63 / 288
 * Category: Trees
 * Approach: Subtree depth sum tracking global max
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

struct TreeNode { int val; TreeNode *left, *right; TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} };
class Solution {
    int maxDiam = 0;
    int dfs(TreeNode* root) {
        if (!root) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        maxDiam = max(maxDiam, left + right);
        return 1 + max(left, right);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return maxDiam;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    TreeNode root(1); int res = s.diameterOfBinaryTree(&root);

    cout << "Passed test for Diameter of Binary Tree" << endl;
    return 0;
}
