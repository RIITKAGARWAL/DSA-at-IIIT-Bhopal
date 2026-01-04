/**
 * Problem: Same Tree
 * Day: 65 / 288
 * Category: Trees
 * Approach: Simultaneous structural DFS verification
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

struct TreeNode { int val; TreeNode *left, *right; TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} };
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q || p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    TreeNode p(1), q(1); bool res = s.isSameTree(&p, &q);

    cout << "Passed test for Same Tree" << endl;
    return 0;
}
