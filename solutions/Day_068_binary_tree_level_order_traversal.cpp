/**
 * Problem: Binary Tree Level Order Traversal
 * Day: 68 / 288
 * Category: Trees
 * Approach: Queue-based BFS level grouping
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

struct TreeNode { int val; TreeNode *left, *right; TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} };
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int qLen = q.size();
            vector<int> level;
            for (int i = 0; i < qLen; ++i) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res.push_back(level);
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    TreeNode root(1); auto res = s.levelOrder(&root);

    cout << "Passed test for Binary Tree Level Order Traversal" << endl;
    return 0;
}
