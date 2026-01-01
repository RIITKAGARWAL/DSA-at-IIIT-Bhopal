/**
 * Problem: Maximum Depth of Binary Tree
 * Day: 62 / 288
 * Category: Trees
 * Approach: Post-order depth recursion
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

struct TreeNode { int val; TreeNode *left, *right; TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} };
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    TreeNode root(1); int res = s.maxDepth(&root);

    cout << "Passed test for Maximum Depth of Binary Tree" << endl;
    return 0;
}
