#include <vector>
#include <unordered_map>
using namespace std;
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} };
class Solution {
    unordered_map<int, int> mp;
    int preIdx = 0;
    TreeNode* build(const vector<int>& pre, int inL, int inR) {
        if (inL > inR) return nullptr;
        int rootVal = pre[preIdx++];
        TreeNode* root = new TreeNode(rootVal);
        int inMid = mp[rootVal];
        root->left = build(pre, inL, inMid - 1);
        root->right = build(pre, inMid + 1, inR);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); ++i) mp[inorder[i]] = i;
        return build(preorder, 0, inorder.size() - 1);
    }
};