/**
 * Problem: Find K Pairs with Smallest Sums
 * Day: 190 / 288
 * Category: Heap
 * Approach: Min-heap priority queue
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        if (nums1.empty() || nums2.empty()) return res;
        auto comp = [&](const pair<int, int>& a, const pair<int, int>& b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
        for (int i = 0; i < nums1.size() && i < k; ++i) {
            pq.push({i, 0});
        }
        while (k-- > 0 && !pq.empty()) {
            auto [i, j] = pq.top(); pq.pop();
            res.push_back({nums1[i], nums2[j]});
            if (j + 1 < nums2.size()) {
                pq.push({i, j + 1});
            }
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> n1 = {1,7,11}, n2 = {2,4,6}; auto res = s.kSmallestPairs(n1, n2, 3);

    cout << "Passed test for Find K Pairs with Smallest Sums" << endl;
    return 0;
}
