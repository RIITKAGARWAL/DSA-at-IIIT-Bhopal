/**
 * Problem: Construct Binary Tree from Preorder and Inorder Traversal
 * Day: 71 / 288
 * Category: Trees
 * Approach: Hash map index lookup
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

struct TreeNode { int val; TreeNode *left, *right; TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} };
class Solution {
    unordered_map<int, int> inMap;
    TreeNode* build(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd) {
        if (preStart > preEnd || inStart > inEnd) return nullptr;
        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = inMap[root->val];
        int numsLeft = inRoot - inStart;
        root->left = build(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1);
        root->right = build(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < (int)inorder.size(); ++i) inMap[inorder[i]] = i;
        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> pre = {3,9,20,15,7}, in = {9,3,15,20,7}; auto res = s.buildTree(pre, in);

    cout << "Passed test for Construct Binary Tree from Preorder and Inorder Traversal" << endl;
    return 0;
}
