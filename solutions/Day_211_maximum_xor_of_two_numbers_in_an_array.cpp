/**
 * Problem: Maximum XOR of Two Numbers in an Array
 * Day: 211 / 288
 * Category: Trie
 * Approach: Bitwise Trie bit-by-bit greedy search
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
            } else {
                curr = curr->children[bit];
            }
        }
        return maxVal;
    }
public:
    int findMaximumXOR(vector<int>& nums) {
        for (int num : nums) insert(num);
        int maxRes = 0;
        for (int num : nums) maxRes = max(maxRes, getMax(num));
        return maxRes;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> nums = {3, 10, 5, 25, 2, 8}; int res = s.findMaximumXOR(nums);

    cout << "Passed test for Maximum XOR of Two Numbers in an Array" << endl;
    return 0;
}
