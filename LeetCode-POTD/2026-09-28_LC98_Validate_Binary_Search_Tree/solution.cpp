#include <vector>
using namespace std;
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} };
class Solution {
    void inorder(TreeNode* node, vector<int>& vals) {
        if (!node) return;
        inorder(node->left, vals);
        vals.push_back(node->val);
        inorder(node->right, vals);
    }
public:
    bool isValidBST(TreeNode* root) {
        vector<int> vals;
        inorder(root, vals);
        for (size_t i = 1; i < vals.size(); ++i) {
            if (vals[i] <= vals[i - 1]) return false;
        }
        return true;
    }
};