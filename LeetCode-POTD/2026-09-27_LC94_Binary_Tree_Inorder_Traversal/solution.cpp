#include <vector>
using namespace std;
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} };
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* curr = root;
        while (curr) {
            if (!curr->left) {
                res.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode* pre = curr->left;
                while (pre->right && pre->right != curr) pre = pre->right;
                if (!pre->right) {
                    pre->right = curr;
                    curr = curr->left;
                } else {
                    pre->right = nullptr;
                    res.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return res;
    }
};