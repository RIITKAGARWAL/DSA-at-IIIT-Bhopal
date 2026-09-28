struct TreeNode { int val; TreeNode *left, *right; TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} };
class Solution {
    bool validate(TreeNode* root, long minVal, long maxVal) {
        if (!root) return true;
        if (root->val <= minVal || root->val >= maxVal) return false;
        return validate(root->left, minVal, root->val) && validate(root->right, root->val, maxVal);
    }
public:
    bool isValidBST(TreeNode* root) {
        return validate(root, -1e18, 1e18);
    }
};