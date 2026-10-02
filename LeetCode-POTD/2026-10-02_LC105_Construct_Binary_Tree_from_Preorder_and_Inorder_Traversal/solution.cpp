#include <vector>
using namespace std;
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} };
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return nullptr;
        int rootVal = preorder[0];
        TreeNode* root = new TreeNode(rootVal);
        int mid = 0;
        while (inorder[mid] != rootVal) mid++;
        vector<int> leftIn(inorder.begin(), inorder.begin() + mid);
        vector<int> rightIn(inorder.begin() + mid + 1, inorder.end());
        vector<int> leftPre(preorder.begin() + 1, preorder.begin() + 1 + mid);
        vector<int> rightPre(preorder.begin() + 1 + mid, preorder.end());
        root->left = buildTree(leftPre, leftIn);
        root->right = buildTree(rightPre, rightIn);
        return root;
    }
};