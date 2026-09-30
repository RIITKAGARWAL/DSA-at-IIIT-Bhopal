#include <vector>
using namespace std;
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} };
class Solution {
    void dfs(TreeNode* node, int level, vector<vector<int>>& ans) {
        if (!node) return;
        if (level >= ans.size()) ans.push_back({});
        ans[level].push_back(node->val);
        dfs(node->left, level + 1, ans);
        dfs(node->right, level + 1, ans);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        dfs(root, 0, ans);
        return ans;
    }
};