/**
 * Problem: Top K Frequent Elements
 * Day: 16 / 288
 * Category: Arrays
 * Approach: Bucket sort frequency mapping
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int n : nums) count[n]++;
        vector<vector<int>> bucket(nums.size() + 1);
        for (auto& p : count) bucket[p.second].push_back(p.first);
        vector<int> res;
        for (int i = bucket.size() - 1; i >= 0 && (int)res.size() < k; --i) {
            for (int val : bucket[i]) {
                res.push_back(val);
                if ((int)res.size() == k) break;
            }
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> nums = {1, 1, 1, 2, 2, 3}; auto res = s.topKFrequent(nums, 2);

    cout << "Passed test for Top K Frequent Elements" << endl;
    return 0;
}
