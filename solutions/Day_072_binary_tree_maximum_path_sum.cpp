/**
 * Problem: Binary Tree Maximum Path Sum
 * Day: 72 / 288
 * Category: Trees
 * Approach: Post-order branch max accumulation
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

struct TreeNode { int val; TreeNode *left, *right; TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} };
class Solution {
    int maxSum = INT_MIN;
    int dfs(TreeNode* node) {
        if (!node) return 0;
        int leftMax = max(dfs(node->left), 0);
        int rightMax = max(dfs(node->right), 0);
        maxSum = max(maxSum, node->val + leftMax + rightMax);
        return node->val + max(leftMax, rightMax);
    }
public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    TreeNode root(-10); root.left = new TreeNode(9); root.right = new TreeNode(20); int res = s.maxPathSum(&root);

    cout << "Passed test for Binary Tree Maximum Path Sum" << endl;
    return 0;
}
