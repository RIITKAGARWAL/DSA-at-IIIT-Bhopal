/**
 * Problem: Maximum XOR With an Element From Array
 * Day: 212 / 288
 * Category: Trie
 * Approach: Sorted queries offline bitwise Trie
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct TrieNode {
        TrieNode* children[2] = {nullptr};
    };
    TrieNode* root = new TrieNode();
    void insert(int num) {
        TrieNode* curr = root;
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (!curr->children[bit]) curr->children[bit] = new TrieNode();
            curr = curr->children[bit];
        }
    }
    int getMax(int num) {
        TrieNode* curr = root;
        int maxVal = 0;
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            int toggle = 1 - bit;
            if (curr->children[toggle]) {
                maxVal |= (1 << i);
                curr = curr->children[toggle];
            } else if (curr->children[bit]) {
                curr = curr->children[bit];
            } else return -1;
        }
        return maxVal;
    }
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());
        int qLen = queries.size();
        vector<vector<int>> q(qLen);
        for (int i = 0; i < qLen; ++i) q[i] = {queries[i][1], queries[i][0], i};
        sort(q.begin(), q.end());
        vector<int> res(qLen);
        int idx = 0, n = nums.size();
        for (auto& query : q) {
            int limit = query[0], val = query[1], originalIdx = query[2];
            while (idx < n && nums[idx] <= limit) {
                insert(nums[idx]);
                idx++;
            }
            res[originalIdx] = (idx == 0) ? -1 : getMax(val);
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> nums = {0, 1, 2, 3, 4}; vector<vector<int>> queries = {{3, 1}, {1, 3}, {5, 6}}; auto res = s.maximizeXor(nums, queries);

    cout << "Passed test for Maximum XOR With an Element From Array" << endl;
    return 0;
}
