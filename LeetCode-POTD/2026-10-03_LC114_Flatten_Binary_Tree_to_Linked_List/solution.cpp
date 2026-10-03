#include <vector>
using namespace std;
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} };
class Solution {
    void pre(TreeNode* node, vector<TreeNode*>& nodes) {
        if (!node) return;
        nodes.push_back(node);
        pre(node->left, nodes);
        pre(node->right, nodes);
    }
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        vector<TreeNode*> nodes;
        pre(root, nodes);
        for (size_t i = 1; i < nodes.size(); ++i) {
            nodes[i - 1]->left = nullptr;
            nodes[i - 1]->right = nodes[i];
        }
    }
};